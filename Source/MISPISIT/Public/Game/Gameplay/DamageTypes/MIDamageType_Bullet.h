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
	}
};