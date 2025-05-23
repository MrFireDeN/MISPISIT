// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemy_Medium.h"


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
}

