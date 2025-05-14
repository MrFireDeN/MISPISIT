// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Command/MIMacroCommand.h"

void UMIMacroCommand::Execute_Implementation()
{
	if (Commands.IsEmpty()) return;

	for (TScriptInterface<IMICommand> Command : Commands)
	{
		Command->Execute_Execute(Command.GetObject());
	}
}

void UMIMacroCommand::Undo_Implementation()
{
	if (Commands.IsEmpty()) return;

	for (TScriptInterface<IMICommand> Command : Commands)
	{
		Command->Execute_Undo(Command.GetObject());
	}
}

void UMIMacroCommand::AddCommand(TScriptInterface<IMICommand> NewCommand)
{
	if (NewCommand == nullptr || !IsValid(NewCommand.GetObject()))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Command is NOT valid"), *GetNameSafe(this));
		return;
	}

	Commands.Add(NewCommand);

	UE_LOG(LogTemp, Log, TEXT("%s: AddCommand"), *GetNameSafe(this));
}
