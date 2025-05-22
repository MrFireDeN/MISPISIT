// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleMediator.h"

#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleElement.h"
#include "Game/DesignPatterns/Behavioral/Memento/MIMemento.h"
#include "Game/DesignPatterns/Behavioral/Memento/MIPuzzleSnapshot.h"

void UMIPuzzleMediator::RegisterElement(FName ElementID, const TScriptInterface<IMIPuzzleElement>& Element)
{
	if (!Elements.Contains(ElementID) && Element.GetObject() != nullptr)
	{
		Elements.Add(ElementID, Element);
	}
}

void UMIPuzzleMediator::NotifyFrom(FName Name, const bool State)
{
	UE_LOG(LogTemp, Display, TEXT("[%s]::NotifyFrom: %s"), *GetNameSafe(this), *Name.ToString());

	if (Name == "Lever")
	{
		if (State)
		{
			SendEventTo("Lamp", FName("TurnOn"));
		}
		else
		{
			SendEventTo("Lamp", FName("TurnOff"));
		}
		bLeverState = State;
	}

	if (Name == "Button")
	{
		bButtonState = State;
	}

	if (Name == "Plate" && bButtonState)
	{
		SendEventTo("Chest", FName("Open"));
		bChestState = true;
	}
}

void UMIPuzzleMediator::SendEventTo(FName ElementID, FName EventName)
{
	if (Elements.Contains(ElementID))
	{
		TScriptInterface<IMIPuzzleElement> Element = *Elements.Find(ElementID);

		if (Element.GetObject() == nullptr) return;
		
		IMIPuzzleElement::Execute_ReceiveEvent(Element.GetObject(), EventName);
	}
}

TScriptInterface<IMIMemento> UMIPuzzleMediator::Save_Implementation()
{
	
	TScriptInterface<IMIMemento> Result = NewObject<UMIPuzzleSnapshot>(this);
	
	const FPuzzleState PuzzleState = {
		bLeverState,
		bButtonState,
		bChestState
	};

	Cast<UMIPuzzleSnapshot>(Result.GetObject())->Init(PuzzleState);

	return Result;
}
