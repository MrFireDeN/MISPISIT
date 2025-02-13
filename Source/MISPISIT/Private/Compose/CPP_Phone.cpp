// CPP_Phone.cpp

#include "Compose/CPP_Phone.h"

ACPP_Phone::ACPP_Phone()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PhoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhoneMesh"));
	PhoneMesh->SetupAttachment(RootComponent);
	PhoneMesh->SetRelativeScale3D(FVector(0.1));
	PhoneMesh->SetRelativeRotation(FRotator(0, 180, 0));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
	
	UAssetLoader::LoadMeshFromAsset(PhoneMesh, "/Game/Project/Models/Compose/SM_Pixel_7a.SM_Pixel_7a");
}

float ACPP_Phone::GetPrice()
{
	return Price;
}

FName ACPP_Phone::GetName()
{
	return Name;
}

void ACPP_Phone::PlaceInBox(AActor* Box)
{
	if (ACPP_ProductBox* Target = Cast<ACPP_ProductBox>(Box))
	{
		APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		UFunction* Function = Pawn->FindFunction(FName("DetachInteractable"));
		void* Params = nullptr;
		Pawn->ProcessEvent(Function, Params);
		
		TScriptInterface<ICPP_IProduct> ProductInterface;
		ProductInterface.SetInterface(Cast<ICPP_IProduct>(this));
		ProductInterface.SetObject(this);
		
		Target->Add(ProductInterface);
		
		AttachToActor(Target, FAttachmentTransformRules::KeepRelativeTransform);
		SetActorRelativeLocation(FVector(0));
		SetActorHiddenInGame(true);
		PhoneMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ACPP_Phone::PlaceInWorld()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(GetActorLocation() + FVector(0, 0, 100));
	SetActorHiddenInGame(false);
	PhoneMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

bool ACPP_Phone::OnAttach()
{
	PhoneMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	return true;
}

bool ACPP_Phone::OnDetach()
{
	PhoneMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	CameraManager = nullptr;

	return true;
}

bool ACPP_Phone::OnPrimaryAction()
{
	if (!CameraManager) return false;

	FVector StartLocation = CameraManager->GetCameraLocation();
	FVector ForwardVector = CameraManager->GetActorForwardVector();
	FVector EndLocation = StartLocation + (ForwardVector * 1000.0f);
	
	FCollisionQueryParams TraceParams(FName(TEXT("LineTrace")), true);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult HitResult;

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility,
		TraceParams
	);

	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor)
		{
			PlaceInBox(HitActor);
		}

		DrawDebugSphere(GetWorld(), HitResult.Location, 10.0f, 12, FColor::Green, false, 5.0f);
	}
	
	return true;
}

