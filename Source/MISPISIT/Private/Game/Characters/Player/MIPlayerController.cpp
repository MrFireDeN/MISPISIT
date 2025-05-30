﻿// MIPlayerController.cpp

#include "Game/Characters/Player/MIPlayerController.h"
#include "Game/Characters/Player/MIPlayerCameraManager.h"
#include "Game/Characters/Player/MIPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Game/Characters/Components/MICharacterInteractComponent.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "Game/Gameplay/Weapons/MIGun.h"
#include "CPP_Interactable.h"

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

		if (JumpAction)
		{
			Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMIPlayerController::HandleJumpStarted);
			Input->BindAction(JumpAction, ETriggerEvent::Canceled, this, &AMIPlayerController::HandleJumpStopped);
			Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMIPlayerController::HandleJumpStopped);
		}

		if (SprintAction)
		{
			Input->BindAction(SprintAction, ETriggerEvent::Started, this, &AMIPlayerController::HandleSprintStarted);
			Input->BindAction(SprintAction, ETriggerEvent::Canceled, this, &AMIPlayerController::HandleSprintStopped);
			Input->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMIPlayerController::HandleSprintStopped);
		}

		if (InteractAction)
		{
			Input->BindAction(InteractAction, ETriggerEvent::Started, this, &AMIPlayerController::HandleInteract);
		}

		if (PrimaryAction)
		{
			Input->BindAction(PrimaryAction, ETriggerEvent::Started, this, &AMIPlayerController::HandlePrimaryAction);
			Input->BindAction(PrimaryAction, ETriggerEvent::Triggered, this, &AMIPlayerController::HandlePrimaryAction_Trigger);
			Input->BindAction(PrimaryAction, ETriggerEvent::Canceled, this, &AMIPlayerController::HandlePrimaryAction_Stopped);
			Input->BindAction(PrimaryAction, ETriggerEvent::Completed, this, &AMIPlayerController::HandlePrimaryAction_Stopped);
		}

		if (SecondaryAction)
		{
			Input->BindAction(SecondaryAction, ETriggerEvent::Started, this, &AMIPlayerController::HandleSecondaryAction);
		}

		if (NumericAction)
		{
			Input->BindAction(NumericAction, ETriggerEvent::Started, this, &AMIPlayerController::HandleNumeric);
		}

		if (ReloadAction)
		{
			Input->BindAction(ReloadAction, ETriggerEvent::Started, this, &AMIPlayerController::HandleReload);
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

void AMIPlayerController::HandleSprintStarted(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->GetCharacterMovement()->StartSprinting();
	}
}

void AMIPlayerController::HandleSprintStopped(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->GetCharacterMovement()->StopSprinting();
	}
}

void AMIPlayerController::HandleJumpStarted(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}
}

void AMIPlayerController::HandleJumpStopped(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->StopJumping();
	}
}

void AMIPlayerController::HandleInteract(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->InteractByHand();
	}
}

void AMIPlayerController::HandlePrimaryAction(const FInputActionValue& Value)
{
	if (const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable())
	{
		Interactable->OnPrimaryAction();
	}
}

void AMIPlayerController::HandlePrimaryAction_Trigger(const FInputActionValue& Value)
{
	if (const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable())
	{
		Interactable->OnPrimaryAction_Trigger();
	}
}

void AMIPlayerController::HandlePrimaryAction_Stopped(const FInputActionValue& Value)
{
	if (const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable())
	{
		Interactable->OnPrimaryAction_Stopped();
	}
}

void AMIPlayerController::HandleSecondaryAction(const FInputActionValue& Value)
{
	if (const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable())
	{
		Interactable->OnSecondaryAction();
	}
}

void AMIPlayerController::HandleNumeric(const FInputActionValue& Value)
{
	const int32 Numeric = Value.Get<float>();
	
	if (const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable())
	{
		Interactable->OnNumericAction(Numeric);
	}
}

void AMIPlayerController::HandleReload(const FInputActionValue& Value)
{
	const TScriptInterface<ICPP_Interactable> Interactable = CheckInteractable();
	
	if (AMIGun* Gun = Cast<AMIGun>(Interactable.GetObject()))
	{
		Gun->Reload();
	}
}

TScriptInterface<ICPP_Interactable> AMIPlayerController::CheckInteractable() &
{
	static const  TScriptInterface<ICPP_Interactable> EmptyInteractable = nullptr;
	
	if (!PlayerCharacter || !PlayerCharacter->GetInteractComponent())
	{
		return EmptyInteractable;
	}

	TScriptInterface<ICPP_Interactable> Interactable = PlayerCharacter->GetInteractComponent()->GetAttachedActor();

	if (!Interactable || !IsValid(Interactable.GetObject()))
	{
		return EmptyInteractable;
	}

	return Interactable;
}
