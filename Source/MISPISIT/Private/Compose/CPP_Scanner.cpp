// CPP_Scanner.cpp

#include "Compose/CPP_Scanner.h"


// Sets default values
ACPP_Scanner::ACPP_Scanner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ScannerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScannerMesh"));
	RootComponent = ScannerMesh;
	ScannerMesh->SetRelativeScale3D(FVector(0.5));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
	
	UAssetLoader::LoadMeshFromAsset(ScannerMesh, "/Game/Project/Models/Compose/SM_Scanner.SM_Scanner");
}

