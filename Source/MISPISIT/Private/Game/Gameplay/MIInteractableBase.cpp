// MIInteractableBase.cpp


#include "Game/Gameplay/MIInteractableBase.h"

#include "Components/BoxComponent.h"
#include "Game/Characters/MICharacterBase.h"
#include "TraceHelper.h"


AMIInteractableBase::AMIInteractableBase()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
}

bool AMIInteractableBase::OnAttach()
{
	CharacterOwner = Cast<AMICharacterBase>(GetAttachParentActor());

	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun attached to non-character actor"));
		return false;
	}
	
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	return true;
}

bool AMIInteractableBase::OnDetach()
{
	CharacterOwner = nullptr;
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	return true;
}

void AMIInteractableBase::BeginPlay()
{
	Super::BeginPlay();

	// Initialize trace helper subsystem
	TraceHelper = GetWorld()->GetSubsystem<UTraceHelper>();
	if (!TraceHelper)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
			TEXT("Failed to load TraceHelper subsystem"));
	}
}

