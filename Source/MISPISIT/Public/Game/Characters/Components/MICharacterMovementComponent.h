// MICharacterMovementComponent.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MICharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMICharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UMICharacterMovementComponent();

	UFUNCTION(BlueprintCallable, Category="Character Movement: Sprinting")
	virtual void StartSprinting();
	
	UFUNCTION(BlueprintCallable, Category="Character Movement: Sprinting")
	virtual void StopSprinting();

	UFUNCTION(BlueprintPure, Category="Character Movement: Sprinting")
	bool IsSprinting() const { return bIsSprinting; }

	UFUNCTION(BlueprintPure, Category="Character Movement: Sprinting")
	bool CanSprint() const;

protected:
	virtual void InitializeComponent() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditDefaultsOnly, Category="Character Movement: Sprinting")
	float SprintSpeed = 1200.f;

	UPROPERTY(EditDefaultsOnly, Category="Character Movement: Sprinting")
	float WalkSpeed = 800.f;

	UPROPERTY(BlueprintReadOnly, Category="Character Movement: Sprinting")
	bool bIsSprinting = false;
};