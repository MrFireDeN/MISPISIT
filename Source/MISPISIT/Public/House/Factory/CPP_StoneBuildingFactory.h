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

	virtual ACPP_Door* CreateDoor(float Width, float Height) override;

	virtual ACPP_Roof* CreateRoof(float Length, float Width) override;
	
	virtual ACPP_Wall* CreateWall(float Length, float Width, float Height) override;

	virtual ACPP_Window* CreateWindow(float Width, float Height) override;
};
