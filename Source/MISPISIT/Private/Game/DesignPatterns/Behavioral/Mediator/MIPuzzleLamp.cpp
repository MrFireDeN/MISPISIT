// MIPuzzleLamp.cpp


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleLamp.h"


AMIPuzzleLamp::AMIPuzzleLamp()
{
	PrimaryActorTick.bCanEverTick = false;

	ID = FName("Lamp");
}

void AMIPuzzleLamp::ReceiveEvent_Implementation(FName EventName)
{
	if (EventName == "TurnOn")
	{
		bIsOn = true;
		OnTurnedOn();
	}

	else if (EventName == "TurnOff")
	{
		bIsOn = false;
		OnTurnedOff();
	}
}
