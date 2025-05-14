// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Observer/MITimeServerSubsystem.h"

#include "Game/DesignPatterns/Behavioral/Observer/MIObserver.h"

void UMITimeServerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&UMITimeServerSubsystem::NotifyObservers,
		1.f,
		true
		);
}

void UMITimeServerSubsystem::Deinitialize()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	Observers.Empty();
	
	Super::Deinitialize();
}

void UMITimeServerSubsystem::Subscribe(UObject* Observer)
{
	Observers.Add(Observer);
}

void UMITimeServerSubsystem::Unsubscribe(UObject* Observer)
{
	Observers.Remove(Observer);
}

void UMITimeServerSubsystem::NotifyObservers()
{
	TimeState++;
	
	for (auto& ObserverPtr : Observers)
	{
		if (UObject* Observer = ObserverPtr.Get())
		{
			if (Observer->GetClass()->ImplementsInterface(UMIObserver::StaticClass()))
			{
				IMIObserver::Execute_OnTimeUpdate(Observer, TimeState);
			}
		}
	}

	UE_LOG(LogTemp, Display, TEXT("[%s] Tick: %d"), *GetNameSafe(this), TimeState);
}
