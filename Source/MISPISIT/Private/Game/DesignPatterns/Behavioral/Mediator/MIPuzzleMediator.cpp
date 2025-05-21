// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleMediator.h"

#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleElement.h"

void UMIPuzzleMediator::RegisterElement(FName ElementID, const TScriptInterface<IMIPuzzleElement>& Element)
{
	if (!Elements.Contains(ElementID) && Element.GetObject() != nullptr)
	{
		Elements.Add(ElementID, Element);
	}
}

void UMIPuzzleMediator::NotifyFrom(FName Name)
{
	UE_LOG(LogTemp, Display, TEXT("[%s]::NotifyFrom: %s"), *GetNameSafe(this), *Name.ToString());
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
