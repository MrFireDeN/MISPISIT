// MIAssetIterator.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIAssetIterator.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UMIAssetIterator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIAssetIterator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	UObject* GetNext();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	UObject* GetPrevious();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	bool HasNext();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	bool HasPrevious();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Iterator")
	void Reset();
};
