// MIPuzzleSnapshot.cpp


#include "Game/DesignPatterns/Behavioral/Memento/MIPuzzleSnapshot.h"

#include "AssetSelection.h"
#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleMediator.h"

UMIPuzzleSnapshot::UMIPuzzleSnapshot()
{
	Mediator = Cast<UMIPuzzleMediator>(GetOuter());

	if (Mediator == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Mediator is NOT valid!!!"), *GetName());
	}
}

void UMIPuzzleSnapshot::Restore_Implementation()
{
	if (Mediator == nullptr) return;

	// LeverState
	if (PuzzleState.LeverState)
	{
		Mediator->SendEventTo("Lever", "ForceOn");
		Mediator->SendEventTo("Lamp", "TurnOn");
	}
	else
	{
		Mediator->SendEventTo("Lever", "ForceOff");
		Mediator->SendEventTo("Lamp", "TurnOff");
	}

	// ButtonState
	if (PuzzleState.ButtonState)
	{
		Mediator->SendEventTo("Button", "ForceOn");
	}
	else
	{
		Mediator->SendEventTo("Button", "ForceOff");
	}

	// ChestState
	if (PuzzleState.ChestState)
	{
		Mediator->SendEventTo("Chest", "Open");
	}
	else
	{
		Mediator->SendEventTo("Chest", "Close");
	}
}
