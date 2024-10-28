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
UCLASS(Abstract, BlueprintType, Blueprintable)
class MISPISIT_API UCPP_BuildingFactory : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Creates a new instance of ACPP_Door with specified dimensions.
	 * 
	 * @param Width The width of the door in meters. Default is 1 meter.
	 * @param Height The height of the door in meters. Default is 2 meters.
	 * 
	 * @return Pointer to the created ACPP_Door object, or nullptr if not implemented.
	 */
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Door* CreateDoor(float Width = 1, float Height = 2);

	/**
	 * @brief Creates a new instance of ACPP_Roof with specified dimensions.
	 * 
	 * @param Length The length of the roof in meters. Default is 4 meters.
	 * @param Width The width of the roof in meters. Default is 4 meters.
	 * 
	 * @return Pointer to the created ACPP_Roof object, or nullptr if not implemented.
	 */
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Roof* CreateRoof(float Length = 4, float Width = 4);

	/**
	 * @brief Creates a new instance of ACPP_Wall with specified dimensions.
	 * 
	 * @param Length The length of the wall in meters. Default is 4 meters.
	 * @param Width The width of the wall in meters. Default is 4 meters.
	 * @param Height The height of the wall in meters. Default is 3 meters.
	 * 
	 * @return Pointer to the created ACPP_Wall object, or nullptr if not implemented.
	 */
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Wall* CreateWall(float Length = 4, float Width = 4, float Height = 3);

	/**
	 * @brief Creates a new instance of ACPP_Window with specified dimensions.
	 * 
	 * @param Width The width of the window in meters. Default is 1.5 meters.
	 * @param Height The height of the window in meters. Default is 1.5 meters.
	 * 
	 * @return Pointer to the created ACPP_Window object, or nullptr if not implemented.
	 */
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Window* CreateWindow(float Width = 1.5, float Height = 1.5);
};
