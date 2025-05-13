// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Command/MICrouchCommand.h"

#include "Game/DesignPatterns/Behavioral/Command/MIAIController_Command.h"
#include "GameFramework/Character.h"

void UMICrouchCommand::Initialize(AMIAIController_Command* InReceiver)
{
	if (!InReceiver)
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Initialize failed - invalid Receiver"), *GetNameSafe(this));
		return;
	}

	Receiver = InReceiver;
}

void UMICrouchCommand::Execute_Implementation()
{
	if (!Receiver)
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Execute failed - invalid Receiver"), *GetNameSafe(this));
		return;
	}

	ACharacter* ControlledCharacter = Cast<ACharacter>(Receiver->GetPawn());
	if (!IsValid(ControlledCharacter))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Execute failed - no controlled pawn"), *GetNameSafe(this));
		return;
	}

	bWasCrouch = ControlledCharacter->bIsCrouched;

	if (bWasCrouch)
	{
		ControlledCharacter->UnCrouch();
	}
	else
	{
		ControlledCharacter->Crouch();
	}
}

void UMICrouchCommand::Undo_Implementation()
{
	Execute_Execute(this);
}
