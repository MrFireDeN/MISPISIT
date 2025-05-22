// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleElementBase.h"

#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleMediator.h"

void AMIPuzzleElementBase::RegisterWithMediator_Implementation(UMIPuzzleMediator* InMediator)
{
	if (InMediator == nullptr) return;

	Mediator = InMediator;
	Mediator->RegisterElement(ID, this);
}

void AMIPuzzleElementBase::NotifyMediator_Implementation(const bool State)
{
	if (IsValid(Mediator.Get()))
	{
		Mediator->NotifyFrom(ID, State);
	}
}
