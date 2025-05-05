// MIDamageType_Fire.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "MIDamageType_Fire.generated.h"

/**
 * DamageType for fire damage with burning effects
 */
UCLASS(Const, Blueprintable, BlueprintType, Abstract, DisplayName = "Fire Damage Type")
class MISPISIT_API UMIDamageType_Fire : public UDamageType
{
    GENERATED_BODY()

public:
    UMIDamageType_Fire(const FObjectInitializer& ObjectInitializer)
        : Super(ObjectInitializer)
    {
        bCausedByWorld = true;
        bScaleMomentumByMass = false;
        bRadialDamageVelChange = false;
        DamageImpulse = 0.0f;
        DestructibleImpulse = 500.0f;
        DestructibleDamageSpreadScale = 2.0f;
        DamageFalloff = 1.2f;
        
        // Fire Properties
        BurnDuration = 5.0f;
        BurnDamagePerSecond = 10.0f;
        bCanSpread = true;
        SpreadInterval = 0.5f;
    }

    /** 
     * Duration of burning effect (seconds) 
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fire Properties",
              meta=(ClampMin="0.1", UIMin="1.0", UIMax="30.0", Tooltip="How long the target will burn"))
    float BurnDuration;

    /** 
     * Damage per second while burning 
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fire Properties",
              meta=(ClampMin="0.1", UIMin="1.0", UIMax="100.0", Tooltip="Damage applied each second while burning"))
    float BurnDamagePerSecond;

    /**
     * Can fire spread to nearby objects
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fire Properties",
              meta=(Tooltip="Whether fire can spread to nearby flammable objects"))
    uint8 bCanSpread : 1;

    /**
     * Time between spread checks (seconds)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fire Properties", meta=(EditCondition="bCanSpread"),
              meta=(ClampMin="0.1", UIMin="0.1", UIMax="2.0", Tooltip="How often fire attempts to spread"))
    float SpreadInterval;
};