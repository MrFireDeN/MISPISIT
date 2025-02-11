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

bool ACPP_ProductBox::OnAttach()
{
	BoxMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxMesh->SetSimulatePhysics(false);
	
	return ICPP_Interactable::OnAttach();
}

bool ACPP_ProductBox::OnDetach()
{
	BoxMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxMesh->SetSimulatePhysics(true);
	
	return ICPP_Interactable::OnDetach();
}

