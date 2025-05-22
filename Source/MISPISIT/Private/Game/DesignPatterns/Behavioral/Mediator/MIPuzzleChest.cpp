// MIPuzzleChest.cpp


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleChest.h"


AMIPuzzleChest::AMIPuzzleChest()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ID = FName("Chest");
}

void AMIPuzzleChest::Open()
{
	if (!bIsOpen)
	{
		bIsOpen = true;
		OnOpen();
		Execute_NotifyMediator(this, bIsOpen);
	}
}

void AMIPuzzleChest::Close()
{
	if (bIsOpen)
	{
		bIsOpen = false;
		OnClose();
		Execute_NotifyMediator(this, bIsOpen);
	}
}

void AMIPuzzleChest::ReceiveEvent_Implementation(FName EventName)
{
	if (EventName == "Open")
	{
		Open();
	}

	if (EventName == "Close")
	{
		Close();
	}
}

