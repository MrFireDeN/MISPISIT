// MIDamageStrategy.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIDamageStrategy.generated.h"

UINTERFACE(BlueprintType)
class MISPISIT_API UMIDamageStrategy : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for defining how damage is modified or applied
 * based on the type of damage, resistances, vulnerabilities, etc.
 */
class MISPISIT_API IMIDamageStrategy
{
	GENERATED_BODY()

public:
	/**
	 * Calculates modified damage based on damage type and modifiers.
	 * @param DamageAmount - Base damage value.
	 * @param DamageEvent - Context of the incoming damage.
	 * @return Final damage after applying resistances or amplifications.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage")
	float ApplyDamage(float DamageAmount, const FDamageEvent& DamageEvent);
};

