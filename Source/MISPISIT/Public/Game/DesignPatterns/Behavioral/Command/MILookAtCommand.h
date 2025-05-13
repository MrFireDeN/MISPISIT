// MILookAtCommand.h

#pragma once

#include "CoreMinimal.h"
#include "MICommand.h"
#include "UObject/Object.h"
#include "MILookAtCommand.generated.h"

class AMIAIController_Command;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta = (DisplayName = "Look To Command"))
class MISPISIT_API UMILookAtCommand : public UObject, public IMICommand
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Command")
	void Initialize(AMIAIController_Command* InReceiver, AActor* InTarget);
	
	virtual void Execute_Implementation() override;
	virtual void Undo_Implementation() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMIAIController_Command> Receiver = nullptr;
    
	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AActor> Target = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	FRotator PrevRotation;
};
