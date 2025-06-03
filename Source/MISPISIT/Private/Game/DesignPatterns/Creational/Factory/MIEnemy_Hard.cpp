// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Hard.h"

#include "Game/Characters/Components/MIArmor.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIArmorDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIHealthDamageHandler.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIShieldDamageHandler.h"
#include "Game/Gameplay/Components/MIArmorComponent.h"
#include "Game/Gameplay/Components/MIShieldComponent.h"
#include "Kismet/KismetSystemLibrary.h"


AMIEnemy_Hard::AMIEnemy_Hard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Material_01(TEXT("/Game/Project/Materials/Characters/MI_Manny_01_Hard.MI_Manny_01_Hard"));
	if (Material_01.Succeeded())
	{
		GetMesh()->SetMaterial(0, Material_01.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Material_02(TEXT("/Game/Project/Materials/Characters/MI_Manny_02_Hard.MI_Manny_02_Hard"));
	if (Material_02.Succeeded())
	{
		GetMesh()->SetMaterial(1, Material_02.Object);
	}

	ArmorComponent = CreateDefaultSubobject<UMIArmorComponent>(TEXT("ArmorComponent"));
	ShieldComponent = CreateDefaultSubobject<UMIShieldComponent>(TEXT("ShieldComponent"));
}

void AMIEnemy_Hard::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 4; ++i)
	{
		UMIArmor* Armor = NewObject<UMIArmor>(this);
		Armor->SetupAttachment(RootComponent);
		ArmorComponent->AddArmor(Armor);
	}
}

void AMIEnemy_Hard::InitializeDamageChain_Implementation()
{
	auto* HealthHandler = NewObject<UMIHealthDamageHandler>(this);
	HealthHandler->SetHealthComponent(GetHealthComponent());
	
	auto* ArmorHandler = NewObject<UMIArmorDamageHandler>(this);
	ArmorHandler->SetArmorComponent(ArmorComponent);
	ArmorHandler->SetNextHandler(HealthHandler);
	
	auto* ShieldHandler = NewObject<UMIShieldDamageHandler>(this);
	ShieldHandler->SetShieldComponent(ShieldComponent);
	ShieldHandler->SetNextHandler(ArmorHandler);
	
	DamageHandlerChain = ShieldHandler;
}
