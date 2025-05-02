// MIArmorDamageHandler.h

#pragma once

#include "CoreMinimal.h"
#include "MIDamageHandler.h"
#include "MIArmorDamageHandler.generated.h"

class UMIArmorComponent;

/**
 * Damage handler responsible for reducing damage using the armor component.
 * Part of the damage chain: Shield → Armor → Health
 */
UCLASS()
class MISPISIT_API UMIArmorDamageHandler : public UMIDamageHandlerBase
{
	GENERATED_BODY()

public:

	/** Sets the armor component used to absorb damage */
	UFUNCTION(BlueprintCallable, Category="Damage")
	void SetArmorComponent(UMIArmorComponent* InArmorComponent);

protected:

	/** Attempts to apply damage to armor and returns amount of damage actually absorbed */
	virtual float ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent) override;

private:

	/** Reference to the armor component that will absorb damage */
	UPROPERTY()
	TObjectPtr<UMIArmorComponent> ArmorComponent;
};
