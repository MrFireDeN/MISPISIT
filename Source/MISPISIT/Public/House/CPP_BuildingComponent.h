// CPP_BuildingComponent.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_BuildingComponent.generated.h"

/**
 * @class ACPP_BuildingComponent
 * @brief A base building component class for managing individual building elements within the game environment.
 * 
 * This class provides the basic structure and functions required to initialize and spawn a building component. 
 * The component displays a spawn message when it is initialized in the game world.
 */
UCLASS()
class MISPISIT_API ACPP_BuildingComponent : public AActor
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief Default constructor, initializes the building component.
	 * 
	 * Sets up the component's properties and disables ticking.
	 */
	ACPP_BuildingComponent();

protected:
	/**
	 * @brief Called when the game begins or when the component is spawned.
	 * 
	 * This method is overridden to trigger the Spawn function, which displays a message indicating
	 * that the component has been successfully spawned.
	 */
	virtual void BeginPlay() override;

	/** 
	 * @brief The name of the component, used for display purposes.
	 * 
	 * Default value is "BuildingComponent". This property is read-only in Blueprints and can be
	 * modified directly in the class for custom components.
	 */
	UPROPERTY(BlueprintReadOnly)
	FString Name = "BuildingComponent";

public:
	/**
	 * @brief Spawns the building component and prints a spawn message.
	 * 
	 * This function is intended to be called once during initialization to confirm
	 * the component’s creation in the game world. It can be overridden in derived classes.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void Spawn();
};
