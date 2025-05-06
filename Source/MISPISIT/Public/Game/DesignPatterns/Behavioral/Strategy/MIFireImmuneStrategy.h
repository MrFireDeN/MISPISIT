// MIFireImmuneStrategy.h

#pragma once

#include "CoreMinimal.h"
#include "MIDamageStrategy.h"
#include "MIDamageStrategyBase.h"
#include "MIFireImmuneStrategy.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MISPISIT_API UMIFireImmuneStrategy : public UMIDamageStrategyBase, public IMIDamageStrategy
{
	GENERATED_BODY()

public:
	virtual float ApplyDamage_Implementation(float DamageAmount, const FDamageEvent& DamageEvent) override;
};
