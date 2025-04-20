// MIPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "../MICharacterBase.h"
#include "MIPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneComponent;

UCLASS()
class MISPISIT_API AMIPlayerCharacter : public AMICharacterBase
{
	GENERATED_BODY()

public:
	explicit AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void ChangeView();

	UFUNCTION(BlueprintPure)
	UCameraComponent* GetCurrentCamera() const { return CurrentCamera; }

protected:
	virtual void BeginPlay() override;
	virtual void PostInitProperties() override;
	virtual void PostInitializeComponents() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> TransitionCamera;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float CameraTransitionSpeed = 5.f;

private:
	TObjectPtr<UCameraComponent> CurrentCamera;

	FTimerHandle CameraTransitionTimerHandle;

	bool bCameraTransiting = false;

	void UpdateCameraTransition();
};
