// MIGun.cpp


#include "Game/Gameplay/Weapons/MIGun.h"

#include "TraceHelper.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Engine/DamageEvents.h"
#include "Flyweight/CPP_FSprayPattern.h"
#include "Flyweight/CPP_SpraySubsystem.h"
#include "Game/Characters/MICharacterBase.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/Gameplay/DamageTypes/MIDamageType_Bullet.h"
#include "Kismet/GameplayStatics.h"


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

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);
	AudioComponent->bOverrideAttenuation = true;
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
	ApplyRecoil();
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
	//AudioComponent->Play();
	ShotIndex++;
	
	UE_LOG(LogTemp, Log, TEXT("[%s] Fire: Shoot"), *GetName());

	TOptional<FHitResult> HitResult = TraceHelper->TraceFromPlayer(5000, false);

	if (!HitResult) return;
	
	const FHitResult& Hit = *HitResult;

	if (!Hit.IsValidBlockingHit()) return;

	SpawnBulletHoleDecal(Hit);
	
	AActor* HitActor = Hit.GetActor();
	
	if (!HitActor) return;

	// Apply damage with proper damage event
	const FPointDamageEvent DamageEvent(Damage, Hit, GetActorForwardVector(), UMIDamageType_Bullet::StaticClass());
	HitActor->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);
}

// Called when the game starts or when spawned
void AMIGun::BeginPlay()
{
	Super::BeginPlay();
	
	SetState(NewObject<UMIGunState_Idle>(this));

	// Initialize trace helper subsystem
	TraceHelper = GetWorld()->GetSubsystem<UTraceHelper>();
	if (!TraceHelper)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
			TEXT("Failed to load TraceHelper subsystem"));
	}

	// Initialize spray pattern subsystem
	SpraySubsystem = GetWorld()->GetSubsystem<UCPP_SpraySubsystem>();
	if (!SpraySubsystem)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
			TEXT("Failed to load SpraySubsystem"));
	}
	
	AudioComponent->SetSound(FireSound);
}

void AMIGun::ApplyRecoil()
{
	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s]::ApplyRecoil: missing CharacterOwner"), *GetNameSafe(this));
		return;
	}

	if (!SpraySubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s]::ApplyRecoil: missing SpraySubsystem"), *GetNameSafe(this));
		return;
	}

	const FCPP_SprayPattern* SprayPattern = SpraySubsystem->GetSprayPattern(SprayType);
	
	if (!SprayPattern)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s]::ApplyRecoil: invalid SprayPattern"), *GetNameSafe(this));
		return;
	}

	const FVector2D Recoil = SprayPattern->GetSprayOffset(ShotIndex);
	UWorld* World = GetWorld();
	
	if (!World) return;

	World->GetTimerManager().ClearTimer(RecoilApplyTimer);
	World->GetTimerManager().ClearTimer(RecoilDurationTimer);

	World->GetTimerManager().SetTimer(RecoilDurationTimer, RecoilDuration, false);

	const float DeltaTime = World->GetDeltaSeconds();
	World->GetTimerManager().SetTimer(RecoilApplyTimer, [this, Recoil, World, DeltaTime]()
	{
		if (!CharacterOwner) 
		{
			World->GetTimerManager().ClearTimer(RecoilApplyTimer);
			return;
		}

		float TimeRemaining = World->GetTimerManager().GetTimerRemaining(RecoilDurationTimer);
		float RecoilProgress = FMath::Pow(FMath::Clamp(TimeRemaining / RecoilDuration, 0.0f, 1.0f), 2.0f);
    
		float FrameRecoil = DeltaTime * RecoilStrength * RecoilProgress;
		CharacterOwner->AddControllerPitchInput(-Recoil.X * FrameRecoil);
		CharacterOwner->AddControllerYawInput(Recoil.Y * FrameRecoil);

		if (TimeRemaining <= 0.f)
		{
			World->GetTimerManager().ClearTimer(RecoilApplyTimer);
		}
	},
	DeltaTime,
	true);
}

void AMIGun::SpawnBulletHoleDecal(const FHitResult& Hit)
{
	if (!Hit.GetComponent() || !BulletHoleMaterial)
	{
		return;
	}

	UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(
		Hit.GetComponent()->GetWorld(),
		BulletHoleMaterial,
		FVector(5, 4, 5),
		Hit.Location,
		Hit.ImpactNormal.Rotation(),
		10.f
	);

	if (Decal)
	{
		Decal->SetFadeScreenSize(0.001f);
		Decal->SetFadeOut(10.f, 1.f);
	}
}
