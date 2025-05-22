// MIPuzzleChest.h

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElementBase.h"
#include "MIPuzzleChest.generated.h"

UCLASS()
class MISPISIT_API AMIPuzzleChest : public AMIPuzzleElementBase
{
	GENERATED_BODY()

public:
	AMIPuzzleChest();

	UFUNCTION(BlueprintCallable, Category = "Chest")
	void Open();

	UFUNCTION(BlueprintCallable, Category = "Chest")
	void Close();

	virtual void ReceiveEvent_Implementation(FName EventName) override;

	UFUNCTION(BlueprintPure, Category = "Chest")
	bool IsOpen() const { return bIsOpen; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Chest")
	bool bIsOpen;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpen();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClose();
};
