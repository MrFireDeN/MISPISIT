// MIPuzzlePlate.cpp


#include "Game/DesignPatterns/Behavioral/Mediator/MIPuzzlePlate.h"

#include "Components/BoxComponent.h"


AMIPuzzlePlate::AMIPuzzlePlate()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetupAttachment(RootComponent);

	ID = "Plate";
}

void AMIPuzzlePlate::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!bIsPressured)
	{
		bIsPressured = true;
		OnPressured();
		Execute_NotifyMediator(this, bIsPressured);
	}
}

void AMIPuzzlePlate::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (bIsPressured)
	{
		bIsPressured = false;
		OnUnpressured();
		Execute_NotifyMediator(this, bIsPressured);
	}
}

