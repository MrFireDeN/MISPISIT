// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MICommand.h"
#include "UObject/Object.h"
#include "MICrouchCommand.generated.h"

class AMIAIController_Command;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta = (DisplayName = "Couch Command"))
class MISPISIT_API UMICrouchCommand : public UObject, public IMICommand
{
	GENERATED_BODY()

public:
	/**
	 * Initializes command with receiver
	 * @param InReceiver - AI controller that will execute the command
	 */
	void Initialize(AMIAIController_Command* InReceiver);
	
	virtual void Execute_Implementation() override;
	virtual void Undo_Implementation() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMIAIController_Command> Receiver = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Command", meta = (AllowPrivateAccess = "true"))
	bool bWasCrouch = false;
};
