// MIHealthComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MIHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMIHealthComponent();

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDeathSignature OnDeath;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnHealthChangedSignature OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual void TakeDamage(const float Damage);

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual void Heal(const float Amount);

	UFUNCTION(BlueprintPure, Category="Health")
	virtual bool IsDead() const { return CurrentHealth <= KINDA_SMALL_NUMBER; };

	UFUNCTION(BlueprintPure, Category="Health")
	virtual float GeCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category="Health")
	virtual float GetMaxHealth() const { return MaxHealth; }

protected:
	virtual void InitializeComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth = 100;
	
	UPROPERTY(VisibleInstanceOnly, Category = "Health")
	float CurrentHealth;

	float UpdateHealth(const float NewHealth);
};
