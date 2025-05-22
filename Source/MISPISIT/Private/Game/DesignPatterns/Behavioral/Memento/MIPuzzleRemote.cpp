// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Memento/MIPuzzleRemote.h"

#include "Game/DesignPatterns/Behavioral/Memento/MIMemento.h"
#include "Game/DesignPatterns/Behavioral/Memento/MIOriginator.h"


bool AMIPuzzleRemote::OnPrimaryAction()
{
	if (Originator && Originator.GetObject())
	{
		Memento = IMIOriginator::Execute_Save(Originator.GetObject());
	}
	
	return Super::OnPrimaryAction();
}

bool AMIPuzzleRemote::OnSecondaryAction()
{
	if (Memento && Memento.GetObject())
	{
		IMIMemento::Execute_Restore(Memento.GetObject());
	}
	
	return Super::OnSecondaryAction();
}
