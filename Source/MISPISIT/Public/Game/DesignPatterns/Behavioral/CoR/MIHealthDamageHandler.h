// MIHealthDamageHandler.h

#pragma once

#include "CoreMinimal.h"
#include "MIDamageHandler.h"
#include "MIHealthDamageHandler.generated.h"

class UMIHealthComponent;

/**
 * Damage handler that applies damage to a health component.
 * This is usually the final handler in a chain (after armor, shield, etc).
 */
UCLASS(Blueprintable)
class MISPISIT_API UMIHealthDamageHandler : public UMIDamageHandlerBase
{
	GENERATED_BODY()
  
public:
	UMIHealthDamageHandler();

	/**
	 * Assigns a health component to this handler.
	 * @param HealthComp - The health component to apply damage to.
	 */
	UFUNCTION(BlueprintCallable, Category="Damage")
	void SetHealthComponent(UMIHealthComponent* HealthComp);

protected:
	/** Applies the damage directly to the health component. */
	virtual float ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent) override;
  
private:
	/** The health component this handler modifies. */
	UPROPERTY()
	TObjectPtr<UMIHealthComponent> HealthComponent;
};
