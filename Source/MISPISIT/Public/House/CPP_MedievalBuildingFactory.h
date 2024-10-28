// CPP_MedievalBuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingFactory.h"
#include "CPP_MedievalBuildingFactory.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UCPP_MedievalBuildingFactory : public UCPP_BuildingFactory
{
	GENERATED_BODY()

public:
	UCPP_MedievalBuildingFactory();

	virtual ACPP_Door* CreateDoor(UWorld* World, float Width = 1, float Height = 2) override;

	virtual ACPP_Roof* CreateRoof(UWorld* World, float Length = 4, float Width = 4) override;
	
	virtual ACPP_Wall* CreateWall(UWorld* World, float Length = 4, float Width = 4, float Height = 3) override;

	virtual ACPP_Window* CreateWindow(UWorld* World, float Width = 1.5, float Height = 1.5) override;
};
