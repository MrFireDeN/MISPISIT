// MIDamageHandler.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIDamageHandler.generated.h"

/**
 * Interface for implementing a Chain of Responsibility for handling damage.
 * Each handler can choose to apply part of the damage and pass the rest to the next handler.
 */
UINTERFACE(BlueprintType)
class MISPISIT_API UMIDamageHandler : public UInterface
{
  GENERATED_BODY()
};

class MISPISIT_API IMIDamageHandler
{
  GENERATED_BODY()

public:
  virtual void HandleDamage(float DamageAmount, const FDamageEvent& DamageEvent) = 0;
  virtual void SetNextHandler(const TScriptInterface<IMIDamageHandler>& Next) = 0;
};

/**
 * Base UObject implementation of a Damage Handler in a Chain of Responsibility.
 */
UCLASS(Abstract, Blueprintable)
class MISPISIT_API UMIDamageHandlerBase : public UObject, public IMIDamageHandler
{
  GENERATED_BODY()

public:
  UMIDamageHandlerBase();

  /**
   * Handles the incoming damage. Implementations may apply part of it and forward the rest.
   * @param DamageAmount - The total amount of incoming damage.
   * @param DamageEvent - Struct containing details about the damage.
   */
  virtual void HandleDamage(float DamageAmount, const FDamageEvent& DamageEvent) override;

  /**
   * Sets the next handler in the chain.
   * @param Next - The next damage handler to call if this one doesn't fully consume the damage.
   */
  virtual void SetNextHandler(const TScriptInterface<IMIDamageHandler>& Next) override;

protected:
  /** Pointer to the next handler in the chain */
  UPROPERTY()
  TScriptInterface<IMIDamageHandler> NextHandler;

  /**
   * Determines if this handler can process the given damage.
   * @return true if this handler can process it.
   */
  virtual bool CanHandle(float DamageAmount, const FDamageEvent& DamageEvent);

  /**
   * Applies the specific effects of this damage handler.
   * @return The amount of damage this handler has processed.
   */
  virtual float ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent);
};
