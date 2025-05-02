// MICharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIDamageHandler.h"
#include "GameFramework/Character.h"
#include "MICharacterBase.generated.h"

class UMICharacterMovementComponent;
class UMICharacterInteractComponent;
class UMIHealthComponent;

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

	/**s
	 * Returns the health component used to track this character's health state.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	FORCEINLINE UMIHealthComponent* GetHealthComponent() const;

	/**
	 * Initiates an interaction by attaching the currently hovered interactable object
	 * to the character's right hand.
	 *
	 * This method is typically called when the player performs an interaction input,
	 * such as pressing a key or triggering an animation event.
	 */
	UFUNCTION(BlueprintCallable, Category = "Character: Interaction")
	virtual void InteractByHand();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	/** Name of the socket or bone on the skeletal mesh to attach interactables to (usually a hand socket). */
	UPROPERTY(EditDefaultsOnly, Category = "Character: Interaction", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FName RightHandName = FName("rightHand");

	/**
	 * Called when the character has received fatal damage.
	 * Override in subclasses to implement custom death behavior (ragdoll, respawn, etc).
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void HandleDeath();
	virtual void HandleDeath_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void InitializeDamageChain();
	virtual void InitializeDamageChain_Implementation();

	UPROPERTY(VisibleAnywhere, Category = "Character")
	TScriptInterface<IMIDamageHandler> DamageHandlerChain;

private:
	/** Component responsible for managing interaction logic (hover, attach, detach). */
	UPROPERTY(VisibleAnywhere, Category = "Character: Interaction", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMICharacterInteractComponent> InteractComponent;
	
	/** Component responsible for managing health logic (take damage, heal, death). */
	UPROPERTY(VisibleAnywhere, Category = "Character: Health", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIHealthComponent> HealthComponent;
};

