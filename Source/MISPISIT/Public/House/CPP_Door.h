#pragma once

#include "CoreMinimal.h"
#include "House/CPP_BuildingComponent.h"
#include "CPP_Door.generated.h"

UCLASS()
class MISPISIT_API ACPP_Door : public ACPP_BuildingComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Height;

public:
	UFUNCTION(BlueprintCallable)
	virtual void Toggle();

	UFUNCTION(BlueprintCallable)
	virtual bool IsOpen();
};
