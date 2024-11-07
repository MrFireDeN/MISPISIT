// CPP_ModernBuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "../CPP_BuildingFactory.h"
#include "../Door/CPP_ModernDoor.h"
#include "../Roof/CPP_ModernRoof.h"
#include "../Wall/CPP_ModernWall.h"
#include "../Window/CPP_ModernWindow.h"
#include "CPP_ModernBuildingFactory.generated.h"

UCLASS()
class MISPISIT_API UCPP_ModernBuildingFactory : public UCPP_BuildingFactory
{
	GENERATED_BODY()

public:
	UCPP_ModernBuildingFactory();

	virtual ACPP_Door* CreateDoor(FTransform Transform) override;

	virtual ACPP_Roof* CreateRoof(FTransform Transform) override;
	
	virtual ACPP_Wall* CreateWall(FTransform Transform, EWallType WallType) override;

	virtual ACPP_Window* CreateWindow(FTransform Transform) override;
};
