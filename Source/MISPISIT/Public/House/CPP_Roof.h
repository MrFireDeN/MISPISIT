// CPP_Roof.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingComponent.h"
#include "CPP_Roof.generated.h"

/**
 * @class ACPP_Roof
 * @brief Represents a roof component in a building with configurable dimensions.
 * 
 * Inherits from ACPP_BuildingComponent and provides properties for setting the roof's
 * length and width, allowing for customizable roof sizes within the game environment.
 */
UCLASS(Abstract)
class MISPISIT_API ACPP_Roof : public ACPP_BuildingComponent
{
	GENERATED_BODY()
	
protected:
	/**
	 * @brief The length of the roof in units.
	 * 
	 * This property is editable in the editor and accessible in Blueprints for setting the roof's size.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Length;

	/**
	 * @brief The width of the roof in units.
	 * 
	 * Allows customization of the roof’s horizontal dimensions in the editor and access within Blueprints.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Width;

	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* RoofMesh;
	
	FString RoofMeshAssetPath;

	virtual void InitializeMeshes() override;
};
