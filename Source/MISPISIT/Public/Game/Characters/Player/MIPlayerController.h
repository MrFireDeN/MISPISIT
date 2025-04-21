// MIPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MIPlayerController.generated.h"

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

private:
	UPROPERTY()
	TObjectPtr<AMIPlayerCharacter> PlayerCharacter;
};