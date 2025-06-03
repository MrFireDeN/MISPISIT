// MIHealthComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Game/DesignPatterns/Behavioral/Strategy/MIDamageStrategyProvider.h"
#include "MIHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIHealthComponent : public UActorComponent, public IMIDamageStrategyProvider
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
	virtual float GetCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category="Health")
	virtual float GetMaxHealth() const { return MaxHealth; }

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Armor")
	TArray<TScriptInterface<IMIDamageStrategy>> DamageStrategies;

	virtual TArray<TScriptInterface<IMIDamageStrategy>> GetDamageStrategies_Implementation() const override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth = 100;
	
	UPROPERTY(VisibleInstanceOnly, Category = "Health")
	float CurrentHealth;

	float UpdateHealth(const float NewHealth);
};
