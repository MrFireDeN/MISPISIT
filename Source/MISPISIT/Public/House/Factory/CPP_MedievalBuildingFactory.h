// CPP_MedievalBuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "../CPP_BuildingFactory.h"
#include "../Door/CPP_MedievalDoor.h"
#include "../Roof/CPP_MedievalRoof.h"
#include "../Wall/CPP_MedievalWall.h"
#include "../Window/CPP_MedievalWindow.h"
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

	virtual ACPP_Door* CreateDoor(FTransform Transform) override;

	virtual ACPP_Roof* CreateRoof(FTransform Transform) override;
	
	virtual ACPP_Wall* CreateWall(FTransform Transform, EWallType WallType) override;

	virtual ACPP_Window* CreateWindow(FTransform Transform) override;
};
