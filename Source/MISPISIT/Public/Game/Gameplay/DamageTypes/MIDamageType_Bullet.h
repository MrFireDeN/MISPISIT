// MIDamageType_Bullet.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "MIDamageType_Bullet.generated.h"

/**
 * DamageType for bullet damage with realistic physical response
 */
UCLASS(Const, Blueprintable, BlueprintType, Abstract, DisplayName = "Bullet Damage Type")
class MISPISIT_API UMIDamageType_Bullet : public UDamageType
{
    GENERATED_BODY()

public:
	UMIDamageType_Bullet(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
		bCausedByWorld = false;
		bScaleMomentumByMass = true;
		bRadialDamageVelChange = false;
		DamageImpulse = 1000.0f;
		DestructibleImpulse = 2000.0f;
		DestructibleDamageSpreadScale = 0.5f;
		DamageFalloff = 1.8f;
		PenetrationPower = 1.0f;
	}

	/**
	 * Bullet penetration (0.0 - does not penetrate, 1.0 - standard, >1.0 - armor-piercing).
	 * Affects penetration of walls, armor and number of targets.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bullet Properties",
			  meta=(ClampMin="0.0", UIMin="0.0", UIMax="5.0", Tooltip="The ability of a bullet to penetrate obstacles and targets"))
	float PenetrationPower;
};