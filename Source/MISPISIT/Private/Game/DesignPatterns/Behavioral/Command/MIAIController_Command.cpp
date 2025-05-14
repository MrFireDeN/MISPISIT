// MIAIController_Command.cpp


#include "Game/DesignPatterns/Behavioral/Command/MIAIController_Command.h"

#include "Game/DesignPatterns/Behavioral/Command/MICommand.h"
#include "Game/DesignPatterns/Behavioral/Command/MICommandHistory.h"


AMIAIController_Command::AMIAIController_Command()
{
	CommandHistory = NewObject<UMICommandHistory>();
	CommandHistory->SetMaxHistorySize(3);
}

void AMIAIController_Command::ExecuteCommand(TScriptInterface<IMICommand> InCommand)
{
	InCommand->Execute_Execute(InCommand.GetObject());

	if (CommandHistory)
	{
		CommandHistory->Push(InCommand.GetObject());
	}
}
