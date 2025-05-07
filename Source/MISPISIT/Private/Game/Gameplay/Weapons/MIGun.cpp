// MIGun.cpp


#include "Game/Gameplay/Weapons/MIGun.h"
#include "AssetLoader.h"
#include "Game/Characters/MICharacterBase.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"


// Sets default values
AMIGun::AMIGun()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

bool AMIGun::OnAttach()
{
	CharacterOwner = Cast<AMICharacterBase>(GetAttachParentActor());

	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun attached to non-character actor"));
		return false;
	}
	
	return true;
}

bool AMIGun::OnDetach()
{
	CharacterOwner = nullptr;
	return true;
}

bool AMIGun::OnPrimaryAction()
{
	StartFire();
	
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
		UE_LOG(LogTemp, Warning, TEXT("[%s] SetState: Invalid Gun State"));
		return;
	}
	
	CurrentState = NewState;
}

// Called when the game starts or when spawned
void AMIGun::BeginPlay()
{
	Super::BeginPlay();
	SetState(NewObject<UMIGunState_Idle>(this));
}
