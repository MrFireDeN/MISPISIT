// MILever.cpp

#include "Game/DesignPatterns/Behavioral/Mediator/MILever.h"


AMILever::AMILever()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	ID = FName("Lever");
}

void AMILever::Toggle()
{
	UE_LOG(LogTemp, Error, TEXT("[%s]: Toggle"), *GetNameSafe(this));
	
	bIsOn = !bIsOn;

	OnLeverToggled(bIsOn);

	Execute_NotifyMediator(this);
}

void AMILever::ReceiveEvent_Implementation(FName EventName)
{
	if (EventName == FName("Reset"))
	{
		bIsOn = false;
		OnLeverToggled(bIsOn);
		return;
	}

	if (EventName == FName("ForceOn"))
	{
		bIsOn = true;
		OnLeverToggled(bIsOn);
		return;
	}

	if (EventName == FName("ForceOff"))
	{
		bIsOn = false;
		OnLeverToggled(bIsOn);
		return;
	}

	UE_LOG(LogTemp, Error, TEXT("[%s]: EventName(%s) is NOT valid"), *GetNameSafe(this), *EventName.ToString());
}

