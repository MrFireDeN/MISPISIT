// MIPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MIPlayerController.generated.h"

class ICPP_Interactable;
class AMIPlayerCharacter;
class AMIPlayerCameraManager;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class MISPISIT_API AMIPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMIPlayerController();
	
	UFUNCTION(BlueprintPure)
	AMIPlayerCharacter* GetPlayerCharacter() const
	{ return PlayerCharacter; }

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void HandleMove(const FInputActionValue& Value);

	UFUNCTION()
	void HandleLook(const FInputActionValue& Value);

	UFUNCTION()
	void HandleSprintStarted(const FInputActionValue& Value);

	UFUNCTION()
	void HandleSprintStopped(const FInputActionValue& Value);

	UFUNCTION()
	void HandleJumpStarted(const FInputActionValue& Value);

	UFUNCTION()
	void HandleJumpStopped(const FInputActionValue& Value);

	UFUNCTION()
	void HandleInteract(const FInputActionValue& Value);

	UFUNCTION()
	void HandlePrimaryAction(const FInputActionValue& Value);

	UFUNCTION()
	void HandlePrimaryAction_Trigger(const FInputActionValue& Value);

	UFUNCTION()
	void HandlePrimaryAction_Stopped(const FInputActionValue& Value);

	UFUNCTION()
	void HandleSecondaryAction(const FInputActionValue& Value);
	
	UFUNCTION()
	void HandleNumeric(const FInputActionValue& Value);

	UFUNCTION()
	void HandleReload(const FInputActionValue& Value);
	
	UPROPERTY(EditDefaultsOnly, Category=Input)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> PrimaryAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> SecondaryAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> SprintAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> ChangeViewAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> InteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> NumericAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> ReloadAction;

private:
	UPROPERTY()
	TObjectPtr<AMIPlayerCharacter> PlayerCharacter;

	TScriptInterface<ICPP_Interactable> CheckInteractable() &;
};
