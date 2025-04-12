// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Player.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
//#include "ToolBuilderUtil.h"
#include "EnhancedInputSubsystemInterface.h"
#include "EnhancedInputSubsystemInterface.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Observer/CPP_HealthComponent.h"

// Sets default values
ACPP_Player::ACPP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CharacterMesh
	GetMesh()->SetRelativeLocation(FVector(0, 0, -89));
	GetMesh()->SetRelativeRotation(FRotator(0, 270, 0));
	
	if (USkeletalMesh* LoadedCharacterMesh = LoadObject<USkeletalMesh>(nullptr, *CharacterMeshAsset))
	{
		GetMesh()->SetSkeletalMesh(LoadedCharacterMesh);
	}

	// AnimBP
	TSubclassOf<UAnimInstance> AnimBP_Quinn =
		LoadClass<UAnimInstance>(nullptr, TEXT("/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn_C"));
	
	if (AnimBP_Quinn)
	{
		GetMesh()->SetAnimInstanceClass(AnimBP_Quinn);
		UE_LOG(LogTemp, Log, TEXT("Anim Loaded"));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Anim NOT Loaded"));
	}

	// SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0, 0, 8.f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 400.f;

	// Camera3P
	Camera3P = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera3P"));
	Camera3P->SetupAttachment(SpringArm);
	Camera3P->bUsePawnControlRotation = true;
	Camera3P->SetAutoActivate(false);
	Camera3P->SetActive(false);

	// Camera1P
	Camera1P = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera1P"));
	Camera1P->SetupAttachment(GetMesh(), TEXT("head"));
	Camera1P->SetRelativeLocation(FVector(10, 12, 0));
	Camera1P->SetRelativeRotation(FRotator(0, 90, 270));
	Camera1P->bUsePawnControlRotation = true;
	Camera1P->SetAutoActivate(false);
	Camera1P->SetActive(false);

	//CameraTransition
	CameraTransition = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraTransition"));
	CameraTransition->SetupAttachment(GetCapsuleComponent());
	CameraTransition->bUsePawnControlRotation = true;
	CameraTransition->SetAutoActivate(false);
	CameraTransition->SetActive(false);

	// Default Settings
	CurrentCamera = Camera1P;
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// HealthComponent
	HealthComponent = CreateDefaultSubobject<UCPP_HealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	CurrentCamera->SetActive(true);

	ShapeFabric = Cast<ACPP_ShapeFabric>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_ShapeFabric::StaticClass()));

	// HealthComponent
	if (HealthComponent)
	{
		HealthComponent->OnDeath.AddDynamic(this, &ACPP_Player::HandleDeath);
	}
}

void ACPP_Player::Move(const FInputActionValue& Value)
{
	FVector2d MovementVector = Value.Get<FVector2d>();
	
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Move1"));

	if (Controller != nullptr)
	{
		AddMovementInput(CurrentCamera->GetForwardVector(), MovementVector.Y);
		AddMovementInput(CurrentCamera->GetRightVector(), MovementVector.X);
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Move2"));
	}
}

void ACPP_Player::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACPP_Player::HandleDeath()
{
	// PlayDeathAnim();
	DisableInput(Cast<APlayerController>(GetController()));
}

// Called every frame
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_Player::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_Player::Look);

		EnhancedInputComponent->BindAction(DrawShapeAction, ETriggerEvent::Started, this, &ACPP_Player::DrawShape);
	}
}

void ACPP_Player::DrawShape()
{
	if (ShapeFabric)
	{
		for (int i = 0; i < ShapeFabric->Shapes.Num(); ++i)
		{
			ShapeFabric->Draw(i);
		}
	}
}

float ACPP_Player::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	HealthComponent->TakeDamage(DamageAmount);
	
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}