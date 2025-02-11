// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerController.h"

ACPP_PlayerController::ACPP_PlayerController()
{
	static
	ConstructorHelpers::FObjectFinder<UInputMappingContext>
	InputMappingContext(TEXT("/Game/Project/Input/IMC_Default.IMC_Default"));
	
	if (InputMappingContext.Succeeded())
	{
		DefaultMappingContext = InputMappingContext.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InputMappingContext NOT found"));
	}

	if (UInputAction* MoveInputAction =
		FindObject<UInputAction>(nullptr, TEXT("Game/Project/Input/Actions/IA_Move.IA_Move")))
	{
		MoveAction = MoveInputAction;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InputAction NOT found"));
	}
}

void ACPP_PlayerController::BeginPlay()
{
	CPP_Player = Cast<ACPP_Player>(GetCharacter());

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			InputSubsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACPP_PlayerController::SetupInputComponent()
{
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{/*
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACPP_PlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACPP_PlayerController::StopJump);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_PlayerController::Look);*/

		// Moving
		if (MoveAction)
		{
			EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_PlayerController::Move);
		}
	}
}

void ACPP_PlayerController::Move(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector2d MovementVector = Value.Get<FVector2d>();
	FVector ForwardDirection = PlayerCameraManager->GetCameraLocation().ForwardVector;
	FVector RightDirection = PlayerCameraManager->GetCameraLocation().RightVector;

	ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
	ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
}

void ACPP_PlayerController::Look(const FInputActionValue& Value)
{
}

void ACPP_PlayerController::Jump()
{
}

void ACPP_PlayerController::StopJump()
{
}

void ACPP_PlayerController::Sprint()
{
}

void ACPP_PlayerController::ChangeView()
{
}
