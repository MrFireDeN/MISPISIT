// CPP_WeaponDirector.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PistolBuilder.h"
#include "CPP_SniperRifleBuilder.h"
#include "CPP_AssaultRifleBuilder.h"
#include "CPP_TacticalRifleBuilder.h"
#include "CPP_WeaponDirector.generated.h"

UCLASS()
class MISPISIT_API ACPP_WeaponDirector : public AActor
{
	GENERATED_BODY()

public:
	ACPP_WeaponDirector();

protected:
	virtual void BeginPlay() override;

	TScriptInterface<ICPP_WeaponBuilder> Builder;

public:
};
