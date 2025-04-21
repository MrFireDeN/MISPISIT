// MICharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MICharacterBase.generated.h"

class UMICharacterMovementComponent;
class UMICharacterInteractComponent;

/**
 * AMICharacterBase
 *
 * Abstract base class for all playable and non-playable characters in MISPISIT.
 * Provides a custom character movement component and a built-in interaction system
 * to support gameplay features such as hovering over interactables and attaching items to sockets.
 *
 * This class should be inherited by any character that needs standardized behavior for
 * interacting with objects or requires extended movement logic.
 */
UCLASS(Abstract, BlueprintType, config = Game)
class MISPISIT_API AMICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	/**
	 * Constructor for initializing the character with custom movement and interaction components.
	 */
	explicit AMICharacterBase(const FObjectInitializer& ObjectInitializer);

	/**
	 * Returns the custom movement component used for this character.
	 * This replaces the default UCharacterMovementComponent with a project-specific subclass.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	FORCEINLINE UMICharacterMovementComponent* GetCharacterMovement() const;

	/**
	 * Returns the character's interaction component.
	 * Used for managing interactable targets, attachment behavior, and hover logic.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	FORCEINLINE UMICharacterInteractComponent* GetInteractComponent() const;

	/**
	 * Called when another actor begins to overlap this character.
	 * Used to trigger hover events for interactable actors.
	 *
	 * @param OtherActor The actor that began overlapping this character.
	 */
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	/**
	 * Called when another actor ends overlap with this character.
	 * Used to clear interaction states for interactable actors.
	 *
	 * @param OtherActor The actor that ended overlapping this character.
	 */
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	/**
	 * Triggers the interaction component to attach the current interactable actor
	 * to the character's right hand socket.
	 * Typically used during pickup animations or interaction events.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character: Interaction")
	virtual void CallAttachToHand();

protected:
	/** Name of the socket or bone on the skeletal mesh to attach interactables to (usually a hand socket). */
	UPROPERTY(EditDefaultsOnly, Category = "Character: Interaction", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FName RightHandName = FName("rightHand");

private:
	/** Component responsible for managing interaction logic (hover, attach, detach). */
	UPROPERTY(VisibleAnywhere, Category = "Character: Interaction", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMICharacterInteractComponent> InteractComponent;
};

