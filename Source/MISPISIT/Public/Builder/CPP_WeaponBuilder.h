// CPP_WeaponBuilder.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_WeaponBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, BlueprintType)
class UCPP_WeaponBuilder : public UInterface
{
  GENERATED_BODY()
};

/**
 * Interface for creating and customizing a weapon.
 * Implement this interface to define the behavior for setting up weapon components.
 */
class MISPISIT_API ICPP_WeaponBuilder
{
  GENERATED_BODY()

public:
  /**
   * Sets the barrel of the weapon with a specific color.
   * @param Color - The color to apply to the barrel.
   * @return True if the barrel was successfully set, false otherwise.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool SetBarrel(FString Color);

  /**
   * Sets the chamber state of the weapon.
   * @param IsOpened True to open the chamber, false to close it.
   * @return True if the chamber state was successfully set, false otherwise.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool SetChamber(bool IsOpened);

  /**
   * Sets the magazine of the weapon with a specific size.
   * @param Size The size of the magazine (e.g., "Small", "Medium", "Large").
   * @return True if the magazine was successfully set, false otherwise.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool SetMagazine(FString Size);

  /**
   * Sets the trigger state of the weapon.
   * @param IsTriggered True to activate the trigger, false to deactivate it.
   * @return True if the trigger state was successfully set, false otherwise.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool SetTrigger(bool IsTriggered);

  /**
   * Sets the scope of the weapon with a specific type.
   * @param Type The type of scope to attach (e.g., "Red Dot", "Sniper", "Thermal").
   * @return True if the scope was successfully set, false otherwise.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool SetScope(FString Type);
 
  /**
   * @brief Resets the builder to its initial state.
   */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "WeaponBuilder")
  bool Reset();
};
