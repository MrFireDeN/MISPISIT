// MIShieldComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MIShieldComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShieldChangedSignature, float, CurrentShield, float, MaxShield);

/**
 * Shield Component — stores shield points and regenerates them after delay when damaged.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIShieldComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  UMIShieldComponent();

  /** Called when shield value changes */
  UPROPERTY(BlueprintAssignable, Category="Shield")
  FOnShieldChangedSignature OnShieldChanged;

  /** Applies incoming damage to the shield. Returns how much damage was absorbed. */
  UFUNCTION(BlueprintCallable, Category="Shield")
  float TakeDamage(float DamageAmount);

  /** Returns current shield value */
  UFUNCTION(BlueprintPure, Category="Shield")
  float GetCurrentShield() const { return CurrentShield; }

  /** Returns max shield capacity */
  UFUNCTION(BlueprintPure, Category="Shield")
  float GetMaxShield() const { return MaxShield; }

  /** Returns true if shield is fully depleted */
  UFUNCTION(BlueprintPure, Category="Shield")
  bool IsDepleted() const { return CurrentShield <= KINDA_SMALL_NUMBER; }

protected:
  virtual void BeginPlay() override;

  void StartRegenTimer();
  void RegenerateShield();
  void ResetRegen();

  void BroadcastShieldChange();

  /** Maximum shield value */
  UPROPERTY(EditDefaultsOnly, Category="Shield")
  float MaxShield = 100.f;

  /** How fast the shield regenerates per second */
  UPROPERTY(EditDefaultsOnly, Category="Shield")
  float RegenRate = 10.f;

  /** How long to wait (in seconds) before regeneration starts */
  UPROPERTY(EditDefaultsOnly, Category="Shield")
  float RegenDelay = 3.f;

  /** Current shield points */
  UPROPERTY(BlueprintReadOnly, Category="Shield", meta=(AllowPrivateAccess=true))
  float CurrentShield;

  /** Timer handle for delaying regeneration */
  FTimerHandle RegenDelayTimerHandle;

  /** Timer handle for ticking regeneration */
  FTimerHandle RegenTickTimerHandle;
};
