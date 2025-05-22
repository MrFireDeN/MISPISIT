// MIMemento.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIMemento.generated.h"

UINTERFACE()
class UMIMemento : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIMemento
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Memento")
	void Restore();
};
