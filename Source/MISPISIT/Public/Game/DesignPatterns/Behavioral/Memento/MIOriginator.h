// MIOriginator.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIOriginator.generated.h"

class IMIMemento;

UINTERFACE()
class UMIOriginator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIOriginator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Memento")
	TScriptInterface<IMIMemento> Save();
};
