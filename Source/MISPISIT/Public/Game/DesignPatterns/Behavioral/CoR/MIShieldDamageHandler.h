// UMIShieldDamageHandler.h

#pragma once

#include "CoreMinimal.h"
#include "MIDamageHandler.h"
#include "MIShieldDamageHandler.generated.h"

class UMIShieldComponent;

/**
 * Shield Damage Handler — part of the damage chain, responsible for absorbing damage using shield.
 */
UCLASS()
class MISPISIT_API UMIShieldDamageHandler : public UMIDamageHandlerBase
{
	GENERATED_BODY()

public:
	UMIShieldDamageHandler();

	/** Sets the shield component to be affected by incoming damage */
	UFUNCTION(BlueprintCallable, Category="Damage|Shield")
	void SetShieldComponent(UMIShieldComponent* InShieldComponent);

protected:
	/** Applies damage to the shield, returns how much was absorbed */
	virtual float ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent) override;

private:
	/** Component responsible for shield mechanics */
	UPROPERTY()
	TObjectPtr<UMIShieldComponent> ShieldComponent;
};
