// CPP_Door.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingComponent.h"
#include "CPP_Door.generated.h"

/**
 * @class ACPP_Door
 * @brief Represents a door component within a building, providing basic open/close functionality.
 * 
 * Inherits from ACPP_BuildingComponent, adding properties for width and height, and functions to toggle
 * the door state and check if it is open.
 */
UCLASS(Abstract)
class MISPISIT_API ACPP_Door : public ACPP_BuildingComponent
{
	GENERATED_BODY()

protected:
	/**
	 * @brief The width of the door in units.
	 * 
	 * This property can be edited in the editor and accessed in Blueprints to customize the door's dimensions.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Width;

	/**
	 * @brief The height of the door in units.
	 * 
	 * Similar to Width, this property can be edited and accessed in Blueprints for door customization.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Height;

public:
	
	/**
	 * @brief Toggles the door's open or closed state, displaying a message based on the action.
	 * 
	 * If the door is open, it closes and prints "Door closed". If it is closed, it opens and prints "Door opened".
	 * Can be overridden for specific door behaviors.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void Toggle();

	/**
	 * @brief Checks whether the door is currently open.
	 * 
	 * @return Returns true if the door is open; false otherwise. Default implementation returns false.
	 * Can be overridden to provide actual open/closed state tracking.
	 */
	UFUNCTION(BlueprintCallable)
	virtual bool IsOpen();

protected:
	/**
	 * @brief Mesh component representing the visual appearance of the door.
	 * 
	 * This component provides the static mesh for the door, allowing it to be rendered in the game world.
	 */
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorFrameMesh;

	FString DoorMeshAssetPath;
	FString DoorFrameMeshAssetPath;

	virtual void InitializeMeshes() override;
};
