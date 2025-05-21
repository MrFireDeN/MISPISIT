// MILever.h

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElementBase.h"
#include "MILever.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API AMILever : public AMIPuzzleElementBase
{
	GENERATED_BODY()

public:
	AMILever();

	UFUNCTION(BlueprintCallable, Category = "Lever")
	void Toggle();

	virtual void ReceiveEvent_Implementation(FName EventName) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lever")
	bool bIsOn = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lever", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UFUNCTION(BlueprintImplementableEvent, Category = "Lever")
	void OnLeverToggled(bool bNewState);
};
