// CPP_StoneBuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "../CPP_BuildingFactory.h"
#include "../Door/CPP_StoneDoor.h"
#include "../Roof/CPP_StoneRoof.h"
#include "../Wall/CPP_StoneWall.h"
#include "../Window/CPP_StoneWindow.h"
#include "CPP_StoneBuildingFactory.generated.h"

UCLASS()
class MISPISIT_API UCPP_StoneBuildingFactory : public UCPP_BuildingFactory
{
	GENERATED_BODY()

public:
	UCPP_StoneBuildingFactory();

	virtual ACPP_Door* CreateDoor(FTransform Transform) override;

	virtual ACPP_Roof* CreateRoof(FTransform Transform) override;
	
	virtual ACPP_Wall* CreateWall(FTransform Transform, EWallType WallType) override;

	virtual ACPP_Window* CreateWindow(FTransform Transform) override;
};
