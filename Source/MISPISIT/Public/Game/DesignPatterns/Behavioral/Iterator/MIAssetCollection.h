// MIAssetCollection.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIAssetCollection.generated.h"

class IMIAssetIterator;

UINTERFACE()
class UMIAssetCollection : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIAssetCollection
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	TScriptInterface<IMIAssetIterator> CreateIterator();
};
