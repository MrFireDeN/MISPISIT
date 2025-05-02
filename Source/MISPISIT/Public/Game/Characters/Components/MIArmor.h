// MIArmor.h

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "MIArmor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArmorChangedSignature, float, CurrentArmor, float, MaxArmor);

/**
 * Armor component that represents a single armor piece attached to a character.
 * Can absorb a portion of incoming damage before breaking.
 * Armor has current and maximum values and broadcasts changes via delegate.
 */
UCLASS()
class MISPISIT_API UMIArmor : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:

	/** Constructor */
	UMIArmor();

	/** Called when armor value changes (either increased or reduced) */
	UPROPERTY(BlueprintAssignable, Category="Armor")
	FOnArmorChangedSignature OnArmorChanged;

	/** Applies damage to this armor piece. Returns the amount of damage absorbed. */
	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual float TakeDamage(const float Damage);

	/** Returns true if this armor piece is fully depleted */
	UFUNCTION(BlueprintPure, Category="Armor")
	virtual bool IsBroken() const { return CurrentArmor <= KINDA_SMALL_NUMBER; }

	/** Returns current armor value */
	UFUNCTION(BlueprintPure, Category="Armor")
	virtual float GetCurrentArmor() const { return CurrentArmor; }

	/** Returns max armor value */
	UFUNCTION(BlueprintPure, Category="Armor")
	virtual float GetMaxArmor() const { return MaxArmor; }

protected:
	virtual void BeginPlay() override;

	/** Maximum armor value this component can hold */
	UPROPERTY(EditDefaultsOnly, Category="Armor", meta=(AllowPrivateAccess=true))
	float MaxArmor = 25;

	/** Current armor value */
	UPROPERTY(BlueprintReadOnly, Category = "Armor", meta=(AllowPrivateAccess=true))
	float CurrentArmor;

	/** Updates armor value and fires delegate if needed */
	float UpdateArmor(const float NewArmor);
};

