// CPP_ProductBox.cpp

#include "Compose/CPP_ProductBox.h"

ACPP_ProductBox::ACPP_ProductBox()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhoneMesh"));
	BoxMesh->SetupAttachment(RootComponent);
	BoxMesh->SetRelativeScale3D(FVector(0.25));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
	
	UAssetLoader::LoadMeshFromAsset(BoxMesh, "/Script/Engine.StaticMesh'/Game/Project/Models/Compose/SM_PaperBox.SM_PaperBox'");
}

bool ACPP_ProductBox::Add(TScriptInterface<ICPP_IProduct> Child)
{
	if (!Child)
	{
		return false;
	}
	
	for (const auto BoxChild : BoxChildren)
	{
		if (Child == BoxChild)
		{
			return false;
		}
	}

	BoxChildren.Add(Child);

	SetActorScale3D(GetActorScale3D() + FVector(0.25));
	
	return true;
}

bool ACPP_ProductBox::Remove(TScriptInterface<ICPP_IProduct> Child)
{
	for (const auto BoxChild : BoxChildren)
	{
		if (Child == BoxChild)
		{
			Child->PlaceInWorld();
			BoxChildren.Remove(Child);
			return true;
		}
	}

	return false;
}

bool ACPP_ProductBox::Remove(int ChildIndex)
{
	if (ChildIndex < BoxChildren.Num())
	{
		return Remove(BoxChildren[ChildIndex]);
	}
	return false;
}

float ACPP_ProductBox::GetPrice()
{
	float Price = 0;

	for (const auto BoxChild : BoxChildren)
	{
		Price += BoxChild->GetPrice();
	}
	
	return Price + 10;
}

FName ACPP_ProductBox::GetName()
{
	FString Names = "Box: {";

	for (const auto BoxChild : BoxChildren)
	{
		Names.Append(BoxChild->GetName().ToString());
		
		if (BoxChildren.Last() != BoxChild)
		{
			Names.Append(", ");
		}
	}
	
	Names.Append("}");
	
	return *Names;
}

void ACPP_ProductBox::PlaceInBox(AActor* Box)
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
		BoxMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ACPP_ProductBox::PlaceInWorld()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(GetActorLocation() + FVector(0, 0, 100));
	SetActorHiddenInGame(false);
	BoxMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

bool ACPP_ProductBox::OnAttach()
{
	BoxMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxMesh->SetSimulatePhysics(false);

	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	
	return ICPP_Interactable::OnAttach();
}

bool ACPP_ProductBox::OnDetach()
{
	BoxMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxMesh->SetSimulatePhysics(true);

	CameraManager = nullptr;
	
	return ICPP_Interactable::OnDetach();
}

bool ACPP_ProductBox::OnPrimaryAction()
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

bool ACPP_ProductBox::OnNumericAction(const int Digit)
{
	return Remove(Digit-1);
}

