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

	virtual ACPP_Door* CreateDoor(float Width = 1, float Height = 2) override;

	virtual ACPP_Roof* CreateRoof(float Length = 4, float Width = 4) override;
	
	virtual ACPP_Wall* CreateWall(float Length = 4, float Width = 4, float Height = 3) override;

	virtual ACPP_Window* CreateWindow(float Width = 1.5, float Height = 1.5) override;
};