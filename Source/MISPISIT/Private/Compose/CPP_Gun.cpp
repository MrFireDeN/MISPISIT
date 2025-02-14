// Fill out your copyright notice in the Description page of Project Settings.


#include "Compose/CPP_Gun.h"

ACPP_Gun::ACPP_Gun()
{
	ProductMesh->SetRelativeScale3D(FVector(0.5));
	
	UAssetLoader::LoadMeshFromAsset(ProductMesh, "/Game/Project/Models/Weapons/Colored_Guns_OTs-14_Groza.Colored_Guns_OTs-14_Groza");
	
	Name = "OTs-14 Groza";
	Price = 1500;
}
