// MICommandHistory.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MICommandHistory.generated.h"

class IMICommand;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MISPISIT_API UMICommandHistory : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Command History")
	void Push(TScriptInterface<IMICommand> InCommand);

	UFUNCTION(BlueprintCallable, Category="Command History")
	void Pop();

	UFUNCTION(BlueprintCallable, Category="Command History")
	void Clear();
	
	UFUNCTION(BlueprintCallable, Category="Command History")
	void UndoLast();

	UFUNCTION(BlueprintCallable, Category="Command History")
	void SetMaxHistorySize(int32 NewSize);

private:
	UPROPERTY()
	TArray<TScriptInterface<IMICommand>> Commands;

	UPROPERTY()
	int32 MaxHistorySize = 10;
};
