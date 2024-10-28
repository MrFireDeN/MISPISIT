// CPP_BuildingFactory.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_Door.h"
#include "CPP_Roof.h"
#include "CPP_Wall.h"
#include "CPP_Window.h"
#include "CPP_BuildingFactory.generated.h"

/**
 * @class UCPP_BuildingFactory
 * @brief Abstract factory class for creating building components, including doors, roofs, walls, and windows.
 * 
 * This class defines the interface for creating various types of building components.
 * Each component creation function can be overridden by subclasses to provide specific implementations.
 */
UCLASS(Abstract)
class MISPISIT_API UCPP_BuildingFactory : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Creates a new instance of ACPP_Door.
	 * 
	 * This function should be overridden in subclasses to create and return a door instance.
	 * 
	 * @return Pointer to the created ACPP_Door object, or nullptr if not implemented.
	 */
	virtual ACPP_Door* CreateDoor();

	/**
	 * @brief Creates a new instance of ACPP_Roof.
	 * 
	 * This function should be overridden in subclasses to create and return a roof instance.
	 * 
	 * @return Pointer to the created ACPP_Roof object, or nullptr if not implemented.
	 */
	virtual ACPP_Roof* CreateRoof();

	/**
	 * @brief Creates a new instance of ACPP_Wall.
	 * 
	 * This function should be overridden in subclasses to create and return a wall instance.
	 * 
	 * @return Pointer to the created ACPP_Wall object, or nullptr if not implemented.
	 */
	virtual ACPP_Wall* CreateWall();

	/**
	 * @brief Creates a new instance of ACPP_Window.
	 * 
	 * This function should be overridden in subclasses to create and return a window instance.
	 * 
	 * @return Pointer to the created ACPP_Window object, or nullptr if not implemented.
	 */
	virtual ACPP_Window* CreateWindow();
};
