// MIBulletDamageStrategy.h

#pragma once

#include "CoreMinimal.h"
#include "MIDamageStrategy.h"
#include "MIDamageStrategyBase.h"
#include "MIBulletDamageStrategy.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UMIBulletDamageStrategy : public UMIDamageStrategyBase, public IMIDamageStrategy
{
	GENERATED_BODY()

public:
	virtual float ApplyDamage_Implementation(float DamageAmount, const FDamageEvent& DamageEvent) override;
};
