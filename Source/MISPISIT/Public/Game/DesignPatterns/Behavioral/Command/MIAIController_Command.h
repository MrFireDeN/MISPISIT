// MIAIController_Command.h

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MIAIController_Command.generated.h"

class IMICommand;
class UMICommandHistory;

UCLASS()
class MISPISIT_API AMIAIController_Command : public AAIController
{
	GENERATED_BODY()

public:
	AMIAIController_Command();

	UFUNCTION(BlueprintCallable, Category="Command History")
	FORCEINLINE UMICommandHistory* GetCommandHistory() { return CommandHistory; }

	UFUNCTION(BlueprintCallable, Category="Command History")
	void ExecuteCommand(TScriptInterface<IMICommand> InCommand);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Command History")
	TObjectPtr<UMICommandHistory> CommandHistory;
};
