// MIDamageStrategyBase.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MIDamageStrategyBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class MISPISIT_API UMIDamageStrategyBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageModifier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FName Tag = NAME_None;
};
