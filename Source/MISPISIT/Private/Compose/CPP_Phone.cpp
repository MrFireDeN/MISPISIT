// CPP_Phone.cpp

#include "Compose/CPP_Phone.h"

#include "Kismet/KismetSystemLibrary.h"

ACPP_Phone::ACPP_Phone()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PhoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhoneMesh"));
	PhoneMesh->SetupAttachment(RootComponent);
	PhoneMesh->SetRelativeScale3D(FVector(0.1));
	PhoneMesh->SetRelativeRotation(FRotator(0, 180, 0));
	//PhoneMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

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

void ACPP_Phone::PlaceInBox()
{
	ICPP_IProduct::PlaceInBox();
}

bool ACPP_Phone::OnAttach()
{
	PhoneMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	return true;
}

bool ACPP_Phone::OnDetach()
{
	PhoneMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	return true;
}

