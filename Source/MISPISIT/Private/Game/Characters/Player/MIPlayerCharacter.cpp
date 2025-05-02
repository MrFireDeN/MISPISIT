// MIPlayerCharacter.cpp

#include "Game/Characters/Player/MIPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "Game/Gameplay/Components/MIArmorComponent.h"
#include "Game/Gameplay/Components/MIShieldComponent.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIArmorDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIHealthDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIShieldDamageHandler.h"
#include "Game/Gameplay/Components/MIHealthComponent.h"
#include "GameFramework/SpringArmComponent.h"


AMIPlayerCharacter::AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	// CharacterMesh
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, 270, 0));

	// SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->SetRelativeLocation(FVector(0, 0, 144.f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 150.f;

	// ThirdPersonCamera
	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm);
	ThirdPersonCamera->SetRelativeLocation(FVector(0, 50, 0));
	ThirdPersonCamera->bUsePawnControlRotation = false;
	ThirdPersonCamera->SetAutoActivate(false);

	// FirstPersonCamera
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), TEXT("head"));
	FirstPersonCamera->SetRelativeLocation(FVector(8, 15, 0));
	FirstPersonCamera->SetRelativeRotation(FRotator(0, 90, 270));
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->SetAutoActivate(false);

	// TransitionCamera
	TransitionCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TransitionCamera"));
	TransitionCamera->SetupAttachment(GetCapsuleComponent());
	TransitionCamera->bUsePawnControlRotation = true;
	TransitionCamera->SetAutoActivate(false);

	// Default Settings
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Components
	ShieldComponent = CreateDefaultSubobject<UMIShieldComponent>(TEXT("ShieldComponent"));
	ArmorComponent = CreateDefaultSubobject<UMIArmorComponent>(TEXT("ArmorComponent"));
}

void AMIPlayerCharacter::ChangeView()
{
	TransitionCamera->SetWorldLocation(CurrentCamera->GetComponentLocation());
	TransitionCamera->SetActive(true);
	bCameraTransiting = true;
	
	CurrentCamera->SetActive(false);
	
	if (CurrentCamera == FirstPersonCamera)
	{
		CurrentCamera = ThirdPersonCamera;
		bUseControllerRotationYaw = false;
	}
	else
	{
		CurrentCamera = FirstPersonCamera;
		bUseControllerRotationYaw = true;
	}

	GetWorldTimerManager().SetTimer(CameraTransitionTimerHandle, this, &AMIPlayerCharacter::UpdateCameraTransition, 0.01f, true);
}

float AMIPlayerCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	if (DamageHandlerChain == nullptr || GetHealthComponent()->IsDead()) return 0.f;

	const float ActualDamage = ACharacter::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	DamageHandlerChain->HandleDamage(ActualDamage, DamageEvent);

	if (GetHealthComponent()->IsDead())
	{
		HandleDeath();
	}
	
	return ActualDamage;
}

void AMIPlayerCharacter::PostInitProperties()
{
	Super::PostInitProperties();
	
	if (!CurrentCamera)
	{
		CurrentCamera = FirstPersonCamera;
	}
}

void AMIPlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	CurrentCamera->SetActive(true);
	InitializeDamageChain_Implementation();
}

void AMIPlayerCharacter::InitializeDamageChain_Implementation()
{
	auto* HealthHandler = NewObject<UMIHealthDamageHandler>(this);
	HealthHandler->SetHealthComponent(GetHealthComponent());
	
	auto* ArmorHandler = NewObject<UMIArmorDamageHandler>(this);
	ArmorHandler->SetArmorComponent(ArmorComponent);
	ArmorHandler->SetNextHandler(HealthHandler);
	
	auto* ShieldHandler = NewObject<UMIShieldDamageHandler>(this);
	ShieldHandler->SetShieldComponent(ShieldComponent);
	ShieldHandler->SetNextHandler(ArmorHandler);
	
	DamageHandlerChain = ShieldHandler;
}

void AMIPlayerCharacter::UpdateCameraTransition()
{
	if (!bCameraTransiting) return;

	const FVector CameraTransitionTargetLocation = CurrentCamera->GetComponentLocation();
	const FRotator CameraTransitionTargetRotation = CurrentCamera->GetComponentRotation();

	const FVector CurrentLoc = TransitionCamera->GetComponentLocation();
	const FRotator CurrentRot = TransitionCamera->GetComponentRotation();

	// Interp
	const FVector NewLoc = FMath::VInterpTo(CurrentLoc, CameraTransitionTargetLocation, GetWorld()->DeltaTimeSeconds, CameraTransitionSpeed);
	const FRotator NewRot = FMath::RInterpTo(CurrentRot, CameraTransitionTargetRotation, GetWorld()->DeltaTimeSeconds, CameraTransitionSpeed);

	TransitionCamera->SetWorldLocation(NewLoc);
	TransitionCamera->SetWorldRotation(NewRot);

	// Ending condition
	if (FVector::Dist(NewLoc, CameraTransitionTargetLocation) < 1.0f &&
		FMath::Abs((NewRot - CameraTransitionTargetRotation).GetNormalized().Yaw) < 1.0f)
	{
		FinishCameraTransition();
	}
}

void AMIPlayerCharacter::FinishCameraTransition()
{
	bCameraTransiting = false;
	GetWorldTimerManager().ClearTimer(CameraTransitionTimerHandle);

	TransitionCamera->SetActive(false);
	CurrentCamera->SetActive(true);

}