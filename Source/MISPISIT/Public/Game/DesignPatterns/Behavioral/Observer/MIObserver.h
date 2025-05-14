// MIObserver.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIObserver.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMIObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Observer")
	void OnTimeUpdate(int32 NewTime);
};
