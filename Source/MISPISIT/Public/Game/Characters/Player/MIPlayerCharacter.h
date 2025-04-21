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
	
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TransitionCamera;

	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	float CameraTransitionSpeed = 15.f;

private:
	UPROPERTY()
	TObjectPtr<UCameraComponent> CurrentCamera;

	UPROPERTY()
	FTimerHandle CameraTransitionTimerHandle;

	UPROPERTY()
	bool bCameraTransiting = false;

	UFUNCTION()
	void UpdateCameraTransition();

	UFUNCTION()
	void FinishCameraTransition();
};
