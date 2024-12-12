// AssetLoader.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetLoader.generated.h"

/**
 * A utility class for loading assets dynamically at runtime.
 * This class provides static methods to streamline the process of loading and applying assets, such as meshes.
 */
UCLASS()
class MISPISIT_API UAssetLoader : public UObject
{
	GENERATED_BODY()

public:

	/**
	 * Loads a static mesh asset from a specified path and assigns it to a given UStaticMeshComponent.
	 *
	 * @param MeshComponent - A reference to the UStaticMeshComponent where the loaded mesh will be assigned.
	 *                        Must be valid and not null.
	 * @param AssetPath - The file path of the static mesh asset to load. Must be a valid and non-empty string.
	 * @return True if the mesh asset was successfully loaded and applied to the component, false otherwise.
	 *         Logs an error or warning if loading fails or parameters are invalid.
	 */
	static bool LoadMeshFromAsset(UStaticMeshComponent*& MeshComponent, const FString& AssetPath)
	{
		// Validate parameters
		if (!MeshComponent || AssetPath.IsEmpty())
		{
			UE_LOG(LogTemp, Error, TEXT("Invalid MeshComponent or AssetPath"));
			return false;
		}
    
		// Attempt to load the static mesh
		UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(nullptr, *AssetPath);
		if (!LoadedMesh)
		{
			// Log a warning if loading failed
			UE_LOG(LogTemp, Warning, TEXT("Failed to load mesh asset at path: %s"), *AssetPath);
			return false;
		}

		// Assign the loaded mesh to the component
		MeshComponent->SetStaticMesh(LoadedMesh);
		return true;
	}
};
