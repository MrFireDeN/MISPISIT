// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Medium.h"

#include "Game/DesignPatterns/Behavioral/CoR/MIHealthDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIShieldDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/Strategy/MIBulletDamageStrategy.h"
#include "Game/DesignPatterns/Behavioral/Strategy/MIDamageStrategy.h"
#include "Game/Gameplay/Components/MIHealthComponent.h"
#include "Game/Gameplay/Components/MIShieldComponent.h"


AMIEnemy_Medium::AMIEnemy_Medium(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Material_01(TEXT("/Game/Project/Materials/Characters/MI_Manny_01_Medium.MI_Manny_01_Medium"));
	if (Material_01.Succeeded())
	{
		GetMesh()->SetMaterial(0, Material_01.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Material_02(TEXT("/Game/Project/Materials/Characters/MI_Manny_02_Medium.MI_Manny_02_Medium"));
	if (Material_02.Succeeded())
	{
		GetMesh()->SetMaterial(1, Material_02.Object);
	}
	
	ShieldComponent = CreateDefaultSubobject<UMIShieldComponent>(TEXT("ShieldComponent"));
}

void AMIEnemy_Medium::BeginPlay()
{
	Super::BeginPlay();

	UMIBulletDamageStrategy* BulletDamageStrategy = NewObject<UMIBulletDamageStrategy>(this);
	BulletDamageStrategy->DamageModifier = 0.9f;
	GetHealthComponent()->DamageStrategies.Add(BulletDamageStrategy);
}

void AMIEnemy_Medium::InitializeDamageChain_Implementation()
{
	Super::InitializeDamageChain_Implementation();

	auto* HealthHandler = NewObject<UMIHealthDamageHandler>(this);
	HealthHandler->SetHealthComponent(GetHealthComponent());
	
	auto* ShieldHandler = NewObject<UMIShieldDamageHandler>(this);
	ShieldHandler->SetShieldComponent(ShieldComponent);
	ShieldHandler->SetNextHandler(HealthHandler);
	
	DamageHandlerChain = ShieldHandler;
}

