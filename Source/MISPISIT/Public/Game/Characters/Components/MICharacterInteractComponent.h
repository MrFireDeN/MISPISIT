// MICharacterInteractComponent.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "Components/ActorComponent.h"
#include "MICharacterInteractComponent.generated.h"

class USkeletalMeshComponent;
class UInteractableHelper;

/**
 * Component responsible for handling interaction logic with ICPP_Interactable objects.
 * It supports hover and attachment behavior, providing Blueprint access to current interactable state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MISPISIT_API UMICharacterInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Default constructor */
	UMICharacterInteractComponent();

	/**
	 * Begins interaction hover with a specified interactable target.
	 *
	 * @param Target The interactable object being hovered over.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Interact")
	void StartHover(TScriptInterface<ICPP_Interactable> Target);

	/**
	 * Ends interaction hover with a specified interactable target.
	 *
	 * @param Target The interactable object no longer being hovered.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Interact")
	void EndHover(TScriptInterface<ICPP_Interactable> Target);

	/**
	 * Attaches the currently hovered interactable object to a skeletal mesh component.
	 *
	 * @param TargetMesh The mesh to attach the interactable to.
	 * @param BoneName The bone socket to attach to.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Interact")
	void AttachInteractable(USkeletalMeshComponent* TargetMesh, FName BoneName);

	/**
	 * Detaches the currently attached interactable object, if any.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character Interact")
	void DetachInteractable();

	/**
	 * Returns the current interactable object being hovered.
	 *
	 * @return The current interactable object.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Interact")
	TScriptInterface<ICPP_Interactable> GetInteractable() const { return Interactable; }

	/**
	 * Returns the actor currently attached to the character.
	 *
	 * @return The attached actor, or nullptr if none.
	 */
	UFUNCTION(BlueprintPure, Category = "Character Interact")
	AActor* GetAttachedActor() const { return AttachedActor; }

private:
	/** The interactable object currently being hovered over. */
	UPROPERTY()
	TScriptInterface<ICPP_Interactable> Interactable;

	/** The actor currently attached to the character. */
	UPROPERTY()
	TObjectPtr<AActor> AttachedActor;

	/** Returns whether the given actor is currently being interacted with. */
	bool IsInteractingWith(AActor* Actor) const { return Actor == AttachedActor; }
};