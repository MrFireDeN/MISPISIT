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

	UFUNCTION(BlueprintCallable, Category="Movement")
	virtual void StartSprinting();
	
	UFUNCTION(BlueprintCallable, Category="Movement")
	virtual void StopSprinting();

	UFUNCTION(BlueprintPure, Category="Movement")
	bool IsSprinting() const { return bIsSprinting; }

	UFUNCTION(BlueprintPure, Category="Movement")
	bool CanSprint() const;

protected:
	virtual void InitializeComponent() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float SprintSpeed = 1200.f;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float WalkSpeed = 800.f;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsSprinting = false;
};