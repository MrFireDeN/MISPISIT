// CPP_HealthComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UCPP_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCPP_HealthComponent();

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDeathSignature OnDeath;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnHealthChangedSignature OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual void TakeDamage(float Damage);

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual void Heal(float Amount);

	UFUNCTION(BlueprintPure, Category="Health")
	virtual bool IsDead() const { return CurrentHealth <= 0; };

	UFUNCTION(BlueprintPure, Category="Health")
	virtual float GeCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category="Health")
	virtual float GetMaxHealth() const { return MaxHealth; }

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth = 100;
	
	UPROPERTY(VisibleInstanceOnly, Category = "Health")
	float CurrentHealth;

	float UpdateHealth(float NewHealth);
};
