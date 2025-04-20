// MIPlayerCharacter.cpp

#include "Game/Characters/Player/MIPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMIPlayerCharacter::AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	// CharacterMesh
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, 270, 0));

	// SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0, 0, 72.f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 100.f;

	// Camera3P
	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm);
	ThirdPersonCamera->SetRelativeLocation(FVector(0, 50, 0));
	ThirdPersonCamera->bUsePawnControlRotation = true;
	ThirdPersonCamera->SetAutoActivate(false);
	ThirdPersonCamera->SetActive(false);

	// Camera1P
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), TEXT("head"));
	FirstPersonCamera->SetRelativeLocation(FVector(10, 12, 0));
	FirstPersonCamera->SetRelativeRotation(FRotator(0, 90, 270));
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->SetAutoActivate(false);
	FirstPersonCamera->SetActive(false);

	//CameraTransition
	TransitionCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TransitionCamera"));
	TransitionCamera->SetupAttachment(GetCapsuleComponent());
	TransitionCamera->bUsePawnControlRotation = true;
	TransitionCamera->SetAutoActivate(false);
	TransitionCamera->SetActive(false);

	// Default Settings
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AMIPlayerCharacter::ChangeView()
{
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

	TransitionCamera->SetActive(true);
	TransitionCamera->SetRelativeLocation(CurrentCamera->GetRelativeLocation());
	bCameraTransiting = true;

	// GetWorldTimerManager().SetTimer(CameraTransitionTimerHandle, this, )
}

void AMIPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
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

	if (CurrentCamera)
	{
		CurrentCamera->SetActive(true);
	}
}

void AMIPlayerCharacter::UpdateCameraTransition()
{
	//
}

void AMIPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMIPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

