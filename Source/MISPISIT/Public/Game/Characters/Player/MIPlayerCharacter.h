// MIPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "../MICharacterBase.h"
#include "MIPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneComponent;
class UMIShieldComponent;
class UMIArmorComponent;

UCLASS()
class MISPISIT_API AMIPlayerCharacter : public AMICharacterBase
{
	GENERATED_BODY()

public:
	explicit AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void ChangeView();

	UFUNCTION(BlueprintPure)
	UCameraComponent* GetCurrentCamera() const { return CurrentCamera; }

	FORCEINLINE UMIShieldComponent* GetShieldComponent() const { return ShieldComponent; }
	FORCEINLINE UMIArmorComponent* GetArmorComponent() const { return ArmorComponent; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void PostInitProperties() override;
	virtual void PostInitializeComponents() override;

	virtual void InitializeDamageChain_Implementation() override;
	
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
	
	/** Component responsible for managing armor logic. */
	UPROPERTY(VisibleAnywhere, Category = "Character: Armor", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIArmorComponent> ArmorComponent;
	
	/** Component responsible for managing shield logic. */
	UPROPERTY(VisibleAnywhere, Category = "Character: Shield", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIShieldComponent> ShieldComponent;
};
