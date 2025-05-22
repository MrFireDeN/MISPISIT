// MIPuzzleLamp.h

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElementBase.h"
#include "MIPuzzleLamp.generated.h"

UCLASS()
class MISPISIT_API AMIPuzzleLamp : public AMIPuzzleElementBase
{
	GENERATED_BODY()

public:
	AMIPuzzleLamp();

	virtual void ReceiveEvent_Implementation(FName EventName) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lamp")
	bool bIsOn = false;

	UFUNCTION(BlueprintImplementableEvent, Category="Lamp")
	void OnTurnedOn();

	UFUNCTION(BlueprintImplementableEvent, Category="Lamp")
	void OnTurnedOff();
};
