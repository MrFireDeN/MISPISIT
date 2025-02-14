// CPP_Phone.cpp

#include "Compose/CPP_Phone.h"

ACPP_Phone::ACPP_Phone()
{
	//ACPP_Product();
	
	ProductMesh->SetRelativeScale3D(FVector(0.1));
	ProductMesh->SetRelativeRotation(FRotator(0, 180, 0));
	
	UAssetLoader::LoadMeshFromAsset(ProductMesh, "/Game/Project/Models/Compose/SM_Pixel_7a.SM_Pixel_7a");

	Name = "Google Pixel 7a";
	Price = 1000;
}