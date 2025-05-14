// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Command/MICommandRemote.h"

#include "TraceHelper.h"
#include "Game/Characters/MICharacterBase.h"
#include "Game/DesignPatterns/Behavioral/Command/MIAIController_Command.h"
#include "Game/DesignPatterns/Behavioral/Command/MICommand.h"
#include "Game/DesignPatterns/Behavioral/Command/MICommandHistory.h"
#include "Game/DesignPatterns/Behavioral/Command/MICrouchCommand.h"
#include "Game/DesignPatterns/Behavioral/Command/MILookAtCommand.h"
#include "Game/DesignPatterns/Behavioral/Command/MIMacroCommand.h"
#include "Game/DesignPatterns/Behavioral/Command/MIMoveToCommand.h"


// Sets default values
AMICommandRemote::AMICommandRemote()
{
	PrimaryActorTick.bCanEverTick = false;
}

bool AMICommandRemote::OnPrimaryAction()
{
	if (!TargetController.Get()) return false;
	
	TOptional<FHitResult> HitResult = GetTraceHelper()->TraceFromPlayer();

	if (!HitResult) return false;
	
	const FHitResult& Hit = *HitResult;

	if (!Hit.IsValidBlockingHit()) return false;

	TScriptInterface<IMICommand> Command = NewObject<UMIMoveToCommand>();
	Cast<UMIMoveToCommand>(Command.GetObject())->Initialize(TargetController, Hit.Location);
	
	TargetController->ExecuteCommand(Command);

	if (bIsRecording)
	{
		MacroCommand->AddCommand(Command);
	}

	return true;
}

bool AMICommandRemote::OnSecondaryAction()
{
	if (!TargetController.Get()) return false;
	
	TOptional<FHitResult> HitResult = GetTraceHelper()->TraceFromPlayer();

	if (!HitResult) return false;
	
	const FHitResult& Hit = *HitResult;

	if (!Hit.IsValidBlockingHit()) return false;
	
	AActor* HitActor = Hit.GetActor();
	
	if (!HitActor) return false;

	TScriptInterface<IMICommand> Command = NewObject<UMILookAtCommand>();
	Cast<UMILookAtCommand>(Command.GetObject())->Initialize(TargetController, HitActor);
	
	TargetController->ExecuteCommand(Command);

	if (bIsRecording)
	{
		MacroCommand->AddCommand(Command);
	}

	return true;
}

bool AMICommandRemote::OnNumericAction(const int Digit)
{
	
	switch (Digit)
	{
		case 1:
			{
				TScriptInterface<IMICommand> Command = NewObject<UMICrouchCommand>();
				Cast<UMICrouchCommand>(Command.GetObject())->Initialize(TargetController);
				
				TargetController->ExecuteCommand(Command);

				if (bIsRecording)
				{
					MacroCommand->AddCommand(Command);
				}
				
				return true;
			}
		case 2:
			{
				UMICommandHistory* CommandHistory = TargetController->GetCommandHistory();
				
				if (!CommandHistory) return false;
				
				CommandHistory->UndoLast();
				
				return true;
			}
		case 3:
			{
				StartRecording();
				return true;
			}
		case 4:
			{
				StopRecording();
				return true;
			}
		case 5:
			{
				if (!IsValid(MacroCommand) || bIsRecording) return false;

				TargetController->ExecuteCommand(MacroCommand);
				
				return true;
			}
	}

	return true;
}

void AMICommandRemote::BeginPlay()
{
	Super::BeginPlay();

	if (Target.Get()) {
		TargetController = Cast<AMIAIController_Command>(Target->GetController());
	}
	
}

void AMICommandRemote::StartRecording()
{
	MacroCommand = NewObject<UMIMacroCommand>();
	bIsRecording = true;
	
	UE_LOG(LogTemp, Log, TEXT("%s: Start Recording"), *GetNameSafe(this));
}

void AMICommandRemote::StopRecording()
{
	bIsRecording = false;
	
	UE_LOG(LogTemp, Log, TEXT("%s: Stop Recording"), *GetNameSafe(this));
}
