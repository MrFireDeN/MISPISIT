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
		UE_LOG(LogTemp, Log, TEXT("MeshLoaded: %s"), *LoadedMesh->GetName());
		MeshComponent->SetStaticMesh(LoadedMesh);
		MeshComponent->RegisterComponent();
		return true;
	}

	/**
	* Creates and attaches a UStaticMeshComponent to the specified actor, loading its static mesh from a given asset path.
	*
	* @param Owner - The AActor to which the new UStaticMeshComponent will be attached. Must be valid and not null.
	* @param ComponentName - The name for the new UStaticMeshComponent. Must be a valid and non-empty string.
	* @param AssetPath - The file path of the static mesh asset to load. Must be a valid and non-empty string.
	* @return True if the static mesh asset was successfully loaded and applied to the component, false otherwise.
	*         Logs errors or warnings if parameters are invalid or loading fails.
	*/ 
	static bool AttachMeshToActorFromAsset(AActor* Owner, const FString& ComponentName, const FString& AssetPath)
	{
	    // Validate the Owner actor
	    if (!Owner)
	    {
	        UE_LOG(LogTemp, Error, TEXT("Invalid Owner actor for AttachMeshToActorFromAsset"));
	        return false;
	    }

	    // Validate the ComponentName
	    if (ComponentName.IsEmpty())
	    {
	        UE_LOG(LogTemp, Error, TEXT("Invalid ComponentName for AttachMeshToActorFromAsset"));
	        return false;
	    }

	    // Validate the AssetPath
	    if (AssetPath.IsEmpty())
	    {
	        UE_LOG(LogTemp, Error, TEXT("Invalid AssetPath for AttachMeshToActorFromAsset"));
	        return false;
	    }

	    // Create a new UStaticMeshComponent
	    UStaticMeshComponent* NewStaticMesh = NewObject<UStaticMeshComponent>(Owner, UStaticMeshComponent::StaticClass(), *ComponentName);
	    if (!NewStaticMesh)
	    {
	        UE_LOG(LogTemp, Error, TEXT("Failed to create UStaticMeshComponent for Actor: %s"), *Owner->GetName());
	        return false;
	    }

	    // Attach the new component to the actor's root component
	    NewStaticMesh->SetupAttachment(Owner->GetRootComponent());

	    // Attempt to load the mesh asset and assign it to the component
	    if (!LoadMeshFromAsset(NewStaticMesh, AssetPath))
	    {
	        UE_LOG(LogTemp, Warning, TEXT("Failed to load mesh for component '%s' from asset path: %s"), *ComponentName, *AssetPath);
	        return false;
	    }

	    // Register the component to make it visible and functional in the world
	    NewStaticMesh->RegisterComponent();
	    UE_LOG(LogTemp, Log, TEXT("Successfully attached mesh to Actor '%s' as Component '%s'"), *Owner->GetName(), *ComponentName);

	    return true;
	}
};
