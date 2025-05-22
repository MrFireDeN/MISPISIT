// MIPuzzleButton.cpp


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleButton.h"

#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzleMediator.h"


AMIPuzzleButton::AMIPuzzleButton()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	ID = FName("Button");
}

void AMIPuzzleButton::Press()
{
	if (bIsActive) return;

	bIsActive = true;
	OnPressed();
	Execute_NotifyMediator(this, bIsActive);

	GetWorld()->GetTimerManager().SetTimer(
		ButtonTimerHandle,
		this,
		&AMIPuzzleButton::Expire,
		ActiveDuration,
		false
		);
}

void AMIPuzzleButton::ReceiveEvent_Implementation(FName EventName)
{
	if (EventName == "Reset")
	{
		bIsActive = false;
		GetWorld()->GetTimerManager().ClearTimer(ButtonTimerHandle);
		OnExpired();
	}
	
	if (EventName == "ForceOn")
	{
		Press();
	}
	
	if (EventName == "ForceOff")
	{
		GetWorld()->GetTimerManager().ClearTimer(ButtonTimerHandle);
		Expire();
	}
}

void AMIPuzzleButton::Expire()
{
	bIsActive = false;
	OnExpired();
	Execute_NotifyMediator(this, bIsActive);
}
