// CPP_AdvancedRemote.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Remote.h"
#include "CPP_AdvancedRemote.generated.h"

UCLASS()
class MISPISIT_API ACPP_AdvancedRemote : public ACPP_Remote
{
	GENERATED_BODY()

public:
	ACPP_AdvancedRemote() {}

	UFUNCTION(BlueprintCallable, Category = "AdvancedRemote")
	virtual bool Mute();

protected:
	float CachedVolume;
};
