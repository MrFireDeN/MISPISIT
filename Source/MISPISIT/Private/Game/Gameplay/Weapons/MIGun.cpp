// MIGun.cpp


#include "Game/Gameplay/Weapons/MIGun.h"
#include "Components/BoxComponent.h"
#include "Game/Characters/MICharacterBase.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"


// Sets default values
AMIGun::AMIGun()
{
	PrimaryActorTick.bCanEverTick = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
}

bool AMIGun::OnAttach()
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

bool AMIGun::OnDetach()
{
	CharacterOwner = nullptr;
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	return true;
}

bool AMIGun::OnPrimaryAction()
{
	StartFire();
	
	return ICPP_Interactable::OnPrimaryAction();
}

bool AMIGun::OnPrimaryAction_Stopped()
{
	StopFire();
	
	return ICPP_Interactable::OnPrimaryAction();
}

void AMIGun::StartFire()
{
	if (CurrentState != nullptr)
	{
		CurrentState->Execute_StartFire(CurrentState.GetObject());
	}
}

void AMIGun::StopFire()
{
	if (CurrentState != nullptr)
	{
		CurrentState->Execute_StopFire(CurrentState.GetObject());
	}
}

void AMIGun::Reload()
{
	if (CurrentState != nullptr)
	{
		CurrentState->Execute_Reload(CurrentState.GetObject());
	}
}

void AMIGun::SetState(TScriptInterface<IMIGunState> NewState)
{
	if (!NewState)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] SetState: Invalid Gun State"), *GetName());
		return;
	}
	
	CurrentState = NewState;
}

void AMIGun::Fire()
{
	UE_LOG(LogTemp, Log, TEXT("[%s] Fire: Shoot"), *GetName());
}

// Called when the game starts or when spawned
void AMIGun::BeginPlay()
{
	Super::BeginPlay();
	SetState(NewObject<UMIGunState_Idle>(this));
}
