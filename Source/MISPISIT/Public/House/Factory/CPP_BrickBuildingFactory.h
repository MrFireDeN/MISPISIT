// CPP_BrickBuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "../CPP_BuildingFactory.h"
#include "../Door/CPP_BrickDoor.h"
#include "../Roof/CPP_BrickRoof.h"
#include "../Wall/CPP_BrickWall.h"
#include "../Window/CPP_BrickWindow.h"
#include "CPP_BrickBuildingFactory.generated.h"

UCLASS()
class MISPISIT_API UCPP_BrickBuildingFactory : public UCPP_BuildingFactory
{
	GENERATED_BODY()

public:
	UCPP_BrickBuildingFactory();

	virtual ACPP_Door* CreateDoor(FTransform Transform) override;

	virtual ACPP_Roof* CreateRoof(float Length, float Width) override;
	
	virtual ACPP_Wall* CreateWall(FTransform Transform, EWallType WallType) override;

	virtual ACPP_Window* CreateWindow(float Width, float Height) override;
};
