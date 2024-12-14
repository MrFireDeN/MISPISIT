// CPP_BuildingFacade.cpp

#include "House/CPP_BuildingFacade.h"

#include "Math/TransformCalculus3D.h"

ACPP_BuildingFacade::ACPP_BuildingFacade()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void ACPP_BuildingFacade::BeginPlay()
{
	Super::BeginPlay();

	BuildingFactories.Add("Brick",
		NewObject<UCPP_BrickBuildingFactory>(
		this,
		UCPP_BrickBuildingFactory::StaticClass(),
		TEXT("BrickBuildingFactory"))
		);

	BuildingFactories.Add("Medieval",
		NewObject<UCPP_MedievalBuildingFactory>(
		this,
		UCPP_MedievalBuildingFactory::StaticClass(),
		TEXT("MedievalBuildingFactory"))
		);

	BuildingFactories.Add("Modern",
		NewObject<UCPP_ModernBuildingFactory>(
		this,
		UCPP_ModernBuildingFactory::StaticClass(),
		TEXT("ModernBuildingFactory"))
		);

	BuildingFactories.Add("Stone",
		NewObject<UCPP_StoneBuildingFactory>(
		this,
		UCPP_StoneBuildingFactory::StaticClass(),
		TEXT("StoneBuildingFactory"))
		);
}

void ACPP_BuildingFacade::CreateHouse(const FString& Style, const FVector& Location)
{
	UCPP_BuildingFactory* CurrentBuildingFactory = *BuildingFactories.Find(Style);

	if (!CurrentBuildingFactory)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s style does NOT support"), *Style);
		return;
	}

	// Walls
	HouseParts.Append(CreateWalls(CurrentBuildingFactory, Location));

	// Windows
	HouseParts.Append(CreateWindows(CurrentBuildingFactory, Location));

	// Door
	AActor* Door = CurrentBuildingFactory->CreateDoor(FTransform(
		FVector(200, 0, 0) + Location));

	HouseParts.Add(Door);

	// Roof
	AActor* Roof = CurrentBuildingFactory->CreateRoof(FTransform(
		FRotator(),
		FVector(0, 0, 300) + Location,
		FVector(6, 3, 2)));
	
	HouseParts.Add(Roof);
}

void ACPP_BuildingFacade::DeleteAll()
{
	for (auto HousePart : HouseParts)
	{
		HousePart->Destroy();
	}
}

void ACPP_BuildingFacade::UpdateHouse(const FString& Style, const FVector& Location)
{
	DeleteAll();
	CreateHouse(Style, Location);
}

TArray<AActor*> ACPP_BuildingFacade::CreateWalls(UCPP_BuildingFactory* BuildingFactory, const FVector& Location)
{
	TArray<AActor*> Walls;

	// Forward Side

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FVector(0, 0, 0) + Location),
		EWallType::Corner)
	);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FVector(100, 0, 0) + Location),
		EWallType::Default)
	);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FVector(200, 0, 0) + Location),
		EWallType::UpDoor)
	);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FVector(300, 0, 0) + Location),
		EWallType::Default)
	);

	// Left Side

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FVector(400, 0, 0) + Location),
		EWallType::ForWindow)
	);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 270, 0), FVector(600, 0, 0) + Location),
		EWallType::Corner)
		);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 270, 0), FVector(600, -100, 0) + Location),
		EWallType::Default)
		);

	// Back Side

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 180, 0), FVector(600, -300, 0) + Location),
		EWallType::Corner)
		);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 180, 0), FVector(500, -300, 0) + Location),
		EWallType::ForWindow)
		);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 180, 0), FVector(400, -300, 0) + Location),
		EWallType::Default)
		);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 180, 0), FVector(300, -300, 0) + Location),
		EWallType::Default)
		);
	
	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 180, 0), FVector(200, -300, 0) + Location),
		EWallType::ForWindow)
		);

	// Right Side

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 90, 0), FVector(0, -300, 0) + Location),
		EWallType::Corner)
		);

	Walls.Add(BuildingFactory->CreateWall(
		FTransform(FRotator(0, 90, 0), FVector(0, -200, 0) + Location),
		EWallType::Default)
		);

	return Walls;
}

TArray<AActor*> ACPP_BuildingFacade::CreateWindows(UCPP_BuildingFactory* BuildingFactory, const FVector& Location)
{
	TArray<AActor*> Windows;

	Windows.Add(BuildingFactory->CreateWindow(
		FTransform(FVector(400, 0, 0) + Location))
		);

	Windows.Add(BuildingFactory->CreateWindow(
		FTransform(FRotator(0, 180, 0), FVector(500, -300, 0) + Location))
		);

	Windows.Add(BuildingFactory->CreateWindow(
		FTransform(FRotator(0, 180, 0), FVector(200, -300, 0) + Location))
		);

	return Windows;
}
