// MIDamageStrategyProvider.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIDamageStrategyProvider.generated.h"

class IMIDamageStrategy;

/**
 * Interface for providing one or more damage strategies (damage "perks")
 * to modify or react to incoming damage. Implemented by components like Health, Shield, or Armor.
 */
UINTERFACE(BlueprintType, MinimalAPI)
class UMIDamageStrategyProvider : public UInterface
{
	GENERATED_BODY()
};

class MISPISIT_API IMIDamageStrategyProvider
{
	GENERATED_BODY()

public:
	/**
	 * Returns an array of strategy objects (perks) that influence how damage is modified.
	 * Each strategy can adjust the final damage based on custom logic like resistances, vulnerabilities, or passive effects.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage")
	TArray<TScriptInterface<IMIDamageStrategy>> GetDamageStrategies() const;
};
