// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/Gameplay/MIInteractableBase.h"
#include "MICommandRemote.generated.h"

class UMIMacroCommand;
class AMIAIController_Command;
class AMICharacterBase;

UCLASS()
class MISPISIT_API AMICommandRemote : public AMIInteractableBase
{
	GENERATED_BODY()

public:
	AMICommandRemote();

	virtual bool OnPrimaryAction() override;
	virtual bool OnSecondaryAction() override;
	virtual bool OnNumericAction(const int Digit) override;

protected:
	virtual void BeginPlay() override;

	void StartRecording();
	void StopRecording();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Remote", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMICharacterBase> Target = nullptr;

private:
	UPROPERTY()
	TObjectPtr<AMIAIController_Command> TargetController;

	UPROPERTY()
	TObjectPtr<UMIMacroCommand> MacroCommand;

	UPROPERTY()
	bool bIsRecording = false;
};
