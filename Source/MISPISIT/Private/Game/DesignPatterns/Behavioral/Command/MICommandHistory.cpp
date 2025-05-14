// MICommandHistory.cpp


#include "Game/DesignPatterns/Behavioral/Command/MICommandHistory.h"

#include "IntVectorTypes.h"
#include "Game/DesignPatterns/Behavioral/Command/MICommand.h"

void UMICommandHistory::Push(TScriptInterface<IMICommand> InCommand)
{
	if (InCommand == nullptr || InCommand.GetObject() == nullptr) return;

	if (Commands.Num() >= MaxHistorySize)
	{
		Commands.RemoveAt(0);
	}
	
	Commands.Push(InCommand);
}

void UMICommandHistory::Pop()
{
	if (Commands.IsEmpty()) return;

	Commands.Pop();
}

void UMICommandHistory::Clear()
{
	if (Commands.IsEmpty()) return;

	Commands.Empty();
}

void UMICommandHistory::UndoLast()
{
	if (Commands.IsEmpty()) return;

	TScriptInterface<IMICommand> LastCommand = Commands.Pop();
	LastCommand->Execute_Undo(LastCommand.GetObject());
}

void UMICommandHistory::SetMaxHistorySize(int32 NewSize)
{
	MaxHistorySize = FMath::Max(NewSize, 1);

	while (Commands.Num() > MaxHistorySize)
	{
		Commands.RemoveAt(0);
	}
}
