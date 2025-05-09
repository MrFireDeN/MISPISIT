﻿// CPP_WeaponDirector.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PistolBuilder.h"
#include "CPP_SniperRifleBuilder.h"
#include "CPP_AssaultRifleBuilder.h"
#include "CPP_TacticalRifleBuilder.h"
#include "CPP_MachineGunBuilder.h"
#include "CPP_SMGBuilder.h"
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
	UFUNCTION(BlueprintCallable, Category = "WeaponDirector")
	virtual bool SetBuilder(TScriptInterface<ICPP_WeaponBuilder> NewBuilder);
	
	UFUNCTION(BlueprintCallable, Category = "WeaponDirector")
	virtual ACPP_Weapon* CreateEmptyWeapon();
	
	UFUNCTION(BlueprintCallable, Category = "WeaponDirector")
	virtual ACPP_Weapon* CreateStandardWeapon();
	
	UFUNCTION(BlueprintCallable, Category = "WeaponDirector")
	virtual ACPP_Weapon* CreateFullWeapon();

private:
	ACPP_Weapon* GetResult();
};
