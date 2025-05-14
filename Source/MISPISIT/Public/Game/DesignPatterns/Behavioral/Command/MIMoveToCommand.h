// MIMoveToCommand.h

#pragma once

#include "CoreMinimal.h"
#include "MICommand.h"
#include "UObject/Object.h"
#include "MIMoveToCommand.generated.h"

class AMIAIController_Command;

/**
 * Command for moving AI to specified location with undo functionality
 */
UCLASS(BlueprintType, Blueprintable, meta = (DisplayName = "Move To Command"))
class MISPISIT_API UMIMoveToCommand : public UObject, public IMICommand
{
	GENERATED_BODY()

public:
	/**
	 * Initializes command with receiver and target location
	 * @param InReceiver - AI controller that will execute the command
	 * @param InLocation - Target location to move to
	 */
	UFUNCTION(BlueprintCallable, Category = "Command")
	void Initialize(AMIAIController_Command* InReceiver, const FVector& InLocation);
	
	virtual void Execute_Implementation() override;
	virtual void Undo_Implementation() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMIAIController_Command> Receiver = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	FVector TargetLocation = FVector::ZeroVector;

	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	FVector PrevLocation = FVector::ZeroVector;
};
