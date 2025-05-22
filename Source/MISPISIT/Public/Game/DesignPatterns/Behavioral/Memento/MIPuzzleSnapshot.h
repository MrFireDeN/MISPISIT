// MIPuzzleSnapshot.h

#pragma once

#include "CoreMinimal.h"
#include "MIMemento.h"
#include "UObject/Object.h"
#include "MIPuzzleSnapshot.generated.h"

class UMIPuzzleMediator;

USTRUCT(BlueprintType)
struct FPuzzleState
{
	GENERATED_BODY()

	bool LeverState = false;
	bool ButtonState = false;
	bool ChestState = false;
};

/**
 * 
 */
UCLASS()
class MISPISIT_API UMIPuzzleSnapshot : public UObject, public IMIMemento
{
	GENERATED_BODY()

public:
	UMIPuzzleSnapshot();
	
	virtual void Restore_Implementation() override;

	void Init(const FPuzzleState& InPuzzleState) { PuzzleState = InPuzzleState; }

protected:
	UPROPERTY()
	FPuzzleState PuzzleState;

	UPROPERTY()
	TObjectPtr<UMIPuzzleMediator> Mediator = nullptr;
};
