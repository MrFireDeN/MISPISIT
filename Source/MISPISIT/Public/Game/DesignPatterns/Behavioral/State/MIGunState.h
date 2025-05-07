// MIGunState.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIGunState.generated.h"

UINTERFACE()
class UMIGunState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIGunState
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartFire();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StopFire();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reload();
};