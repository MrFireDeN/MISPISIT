// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Hard.h"


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
}