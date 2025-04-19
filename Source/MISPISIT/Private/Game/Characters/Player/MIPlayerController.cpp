// MIPlayerController.cpp

#include "Game/Characters/Player/MIPlayerController.h"
#include "Game/Characters/Player/MIPlayerCameraManager.h"
#include "Game/Characters/Player/MIPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AMIPlayerController::AMIPlayerController()
{
	PlayerCameraManagerClass = AMIPlayerCameraManager::StaticClass();
}

void AMIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (const ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AMIPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PlayerCharacter = Cast<AMIPlayerCharacter>(InPawn);
	if (!PlayerCharacter)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("AMIPlayerController::OnPossess() failed to cast %s to PlayerCharacter."),
			*InPawn->GetName()
		);
	}
}

void AMIPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (MoveAction)
		{
			Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMIPlayerController::HandleMove);
		}

		if (LookAction)
		{
			Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMIPlayerController::HandleLook);
		}
	}
}

void AMIPlayerController::HandleMove(const FInputActionValue& Value)
{
	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (PlayerCharacter)
	{
		const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		PlayerCharacter->AddMovementInput(Forward, MoveInput.Y);
		PlayerCharacter->AddMovementInput(Right, MoveInput.X);
	}
}

void AMIPlayerController::HandleLook(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (PlayerCharacter)
	{
		PlayerCharacter->AddControllerYawInput(LookAxisVector.X);
		PlayerCharacter->AddControllerPitchInput(LookAxisVector.Y);
	}
}
