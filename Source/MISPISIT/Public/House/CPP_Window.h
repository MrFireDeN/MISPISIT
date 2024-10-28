// CPP_Window.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingComponent.h"
#include "CPP_Window.generated.h"

/**
 * @class ACPP_Window
 * @brief Represents a window component within a building, with customizable dimensions and light control functionality.
 * 
 * Inherits from ACPP_BuildingComponent and adds properties for width and height, along with functions to toggle and check
 * the state of a light associated with the window.
 */
UCLASS(Abstract)
class MISPISIT_API ACPP_Window : public ACPP_BuildingComponent
{
	GENERATED_BODY()

protected:
	/**
	 * @brief The width of the window in units.
	 * 
	 * This property is editable in the editor and accessible in Blueprints, allowing customization of window size.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Width;

	/**
	 * @brief The height of the window in units.
	 * 
	 * Editable in the editor and accessible in Blueprints, this property defines the vertical dimension of the window.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Height;

public:
	/**
	 * @brief Toggles the window's light on or off and prints a message indicating the new state.
	 * 
	 * If the light is currently on, it turns it off, printing "Light off"; if off, it turns it on, printing "Light on".
	 * Override this function to implement actual light control behavior.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void ToggleLight();

	/**
	 * @brief Checks if the window's light is currently on.
	 * 
	 * @return Returns true if the light is on; false otherwise. Default implementation always returns false.
	 * Can be overridden to reflect the actual light state.
	 */
	UFUNCTION(BlueprintCallable)
	virtual bool IsLightOn();
};
