// CPP_Wall.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingComponent.h"
#include "CPP_Wall.generated.h"

/**
 * @enum EWallType
 * @brief Enumerates the types of walls that can be created.
 */
UENUM(BlueprintType)
enum class EWallType : uint8
{
	Default UMETA(DisplayName = "Default"),
	Corner UMETA(DisplayName = "Corner"),
	UpDoor UMETA(DisplayName = "UpDoor")
};

/**
 * @class ACPP_Wall
 * @brief Represents a wall component in a building, with customizable dimensions.
 * 
 * Inherits from ACPP_BuildingComponent and adds properties for length, width, and height,
 * allowing for flexible wall sizing within the game environment.
 */
UCLASS(Abstract)
class MISPISIT_API ACPP_Wall : public ACPP_BuildingComponent
{
	GENERATED_BODY()

protected:
	/**
	 * @brief The length of the wall in units.
	 * 
	 * This property is editable in the editor and accessible in Blueprints, allowing customization of wall size.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Length;

	/**
	 * @brief The width of the wall in units.
	 * 
	 * Similar to Length, this property can be modified and accessed in Blueprints for defining wall dimensions.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Width;

	/**
	 * @brief The height of the wall in units.
	 * 
	 * This property determines the vertical size of the wall, also editable in the editor and accessible in Blueprints.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Height;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* WallMesh;

	FString WallMeshTileAssetPath;
	FString WallMeshCornerAssetPath;
	FString WallMeshUpDoorAssetPath;
	
	virtual void InitializeMeshes() override;

	/**
	 * @brief The wall type, exposed on spawn for easy customization in the editor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	EWallType WallType;

public:
	virtual void SetWallType(const EWallType NewWallType);
};
