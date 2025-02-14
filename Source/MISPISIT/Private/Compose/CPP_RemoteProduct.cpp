// Fill out your copyright notice in the Description page of Project Settings.


#include "Compose/CPP_RemoteProduct.h"


// Sets default values
ACPP_RemoteProduct::ACPP_RemoteProduct()
{
	ProductMesh->SetRelativeScale3D(FVector(0.5));
	
	UAssetLoader::LoadMeshFromAsset(ProductMesh, "/Game/Project/Models/Bridge/TV_Pixel/SM_TV_Remote.SM_TV_Remote");

	Name = "Pixel Remote";
	Price = 25;
}

