// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemyFactory.h"

#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Easy.h"
#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Hard.h"
#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Medium.h"

AMIEnemyFactory::AMIEnemyFactory()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void AMIEnemyFactory::Start()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMIEnemyFactory::SpawnEnemy, 1, true);
}

void AMIEnemyFactory::Stop()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMIEnemyFactory::SpawnEnemy()
{
	// Генерируем случайную позицию вокруг фабрики
	FVector SpawnLocation = GetActorLocation() + FMath::VRand() * SpawnRadius;
	SpawnLocation.Z = GetActorLocation().Z; // Сохраняем ту же высоту

	EEnemyType EnemyType = static_cast<EEnemyType>(FMath::RandRange(0, 2));

	// Создаем врага
	CreateEnemy(EnemyType, SpawnLocation);
}

AMIEnemy* AMIEnemyFactory::CreateEnemy(const EEnemyType EnemyType, const FVector Location)
{
	FActorSpawnParameters SpawnParameters;
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(Location);
	
	switch (EnemyType)
	{
	case Easy:
		{
			return GetWorld()->SpawnActor<AMIEnemy_Easy>(AMIEnemy_Easy::StaticClass(), SpawnTransform, SpawnParameters);
		}
	case Medium:
		{
			return GetWorld()->SpawnActor<AMIEnemy_Medium>(AMIEnemy_Medium::StaticClass(), SpawnTransform, SpawnParameters);
		}
	case Hard:
		{
			return GetWorld()->SpawnActor<AMIEnemy_Hard>(AMIEnemy_Hard::StaticClass(), SpawnTransform, SpawnParameters);
		}
	default:
		{
			return nullptr;
		}
	}
}
