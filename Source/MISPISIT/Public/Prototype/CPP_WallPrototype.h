// CPP_WallPrototype.h

#pragma once

#include "CoreMinimal.h"
#include "Prototype/CPP_Prototype.h"
#include "../House/CPP_Wall.h"
#include "CPP_WallPrototype.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_WallPrototype : public ACPP_Prototype
{
	GENERATED_BODY()

protected:
	virtual void Initialize(ACPP_Prototype*& Target) override;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* WallMesh;
	
	TMap<FString, FString> WallMeshTileAssetPaths;
	TMap<FString, FString> WallMeshCornerAssetPaths;
	TMap<FString, FString> WallMeshUpDoorAssetPaths;
	TMap<FString, FString> WallMeshForWindowAssetPaths;

	/**
	* @brief The wall type, exposed on spawn for easy customization in the editor.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	EWallType WallType;

public:
	ACPP_WallPrototype();
	
	virtual void SetWallType(const EWallType NewWallType);

	virtual void SetStyle(const FString Name) override;
};
