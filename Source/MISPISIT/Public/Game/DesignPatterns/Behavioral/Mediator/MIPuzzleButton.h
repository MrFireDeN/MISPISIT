// MIPuzzleButton.h

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElementBase.h"
#include "MIPuzzleButton.generated.h"

class UStaticMeshComponent;

UCLASS()
class MISPISIT_API AMIPuzzleButton : public AMIPuzzleElementBase
{
	GENERATED_BODY()

public:
	AMIPuzzleButton();

	UFUNCTION(BlueprintCallable, Category = "Button")
	void Press();

	virtual void ReceiveEvent_Implementation(FName EventName) override;

	UFUNCTION(BlueprintPure, Category = "Button")
	bool IsActive() const { return bIsActive; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Button")
	float ActiveDuration = 5.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Button")
	bool bIsActive = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lever", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	FTimerHandle ButtonTimerHandle;

	void Expire();

	UFUNCTION(BlueprintImplementableEvent, Category = "Button")
	void OnPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Button")
	void OnExpired();
};
