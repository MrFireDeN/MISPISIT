// // CPP_Product.cpp

#include "Compose/CPP_Product.h"


// Sets default values
ACPP_Product::ACPP_Product()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ProductMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProductMesh"));
	ProductMesh->SetupAttachment(RootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
}

float ACPP_Product::GetPrice()
{
	return Price;
}

FName ACPP_Product::GetName()
{
	return Name;
}

void ACPP_Product::PlaceInBox(AActor* Box)
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
		ProductMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ACPP_Product::PlaceInWorld()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(GetActorLocation() + FVector(0, 0, 100));
	SetActorHiddenInGame(false);
	ProductMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

bool ACPP_Product::OnAttach()
{
	ProductMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	return true;
}

bool ACPP_Product::OnDetach()
{
	ProductMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	CameraManager = nullptr;

	return true;
}

bool ACPP_Product::OnPrimaryAction()
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

