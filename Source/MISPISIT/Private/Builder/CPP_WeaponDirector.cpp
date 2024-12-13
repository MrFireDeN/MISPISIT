// CPP_WeaponDirector.cpp

#include "Builder/CPP_WeaponDirector.h"


ACPP_WeaponDirector::ACPP_WeaponDirector()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}


void ACPP_WeaponDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool ACPP_WeaponDirector::SetBuilder(TScriptInterface<ICPP_WeaponBuilder> NewBuilder)
{
	if (NewBuilder)
	{
		Builder = NewBuilder;
		return true;
	}

	return false;
}

ACPP_Weapon* ACPP_WeaponDirector::CreateEmptyWeapon()
{
	Builder->Execute_ResetState(Builder->_getUObject());

	return GetResult();
}

ACPP_Weapon* ACPP_WeaponDirector::CreateStandardWeapon()
{
	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "White");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	
	ACPP_Weapon* Result = nullptr;

	if (auto PistolBuilder = Cast<ACPP_PistolBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Small");
		
		Result = PistolBuilder->GetResult();
	}
	else if (auto SniperRifleBuilder = Cast<ACPP_SniperRifleBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Large");
		
		Result = SniperRifleBuilder->GetResult();
	}
	else if (auto TacticalRifleBuilder = Cast<ACPP_TacticalRifleBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Default");
		
		Result = TacticalRifleBuilder->GetResult();
	}
	else if (auto AssaultRifleBuilder = Cast<ACPP_AssaultRifleBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Default");
		
		Result = AssaultRifleBuilder->GetResult();
	}
	else if (auto MachineGunBuilder = Cast<ACPP_MachineGunBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Large");
		
		Result = MachineGunBuilder->GetResult();
	}
	else if (auto SMGBuilder = Cast<ACPP_SMGBuilder>(Builder.GetObject()))
	{
		Builder->Execute_SetMagazine(Builder.GetObject(), "Default");
		
		Result = SMGBuilder->GetResult();
	}

	return Result;
}

ACPP_Weapon* ACPP_WeaponDirector::CreateFullWeapon()
{
	Builder->Execute_ResetState(Builder->_getUObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "Gold");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	
	ACPP_Weapon* Result = nullptr;

	if (auto PistolBuilder = Cast<ACPP_PistolBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Small");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("Red Dot"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Flashlight"));
		
		Result = PistolBuilder->GetResult();
	}
	else if (auto SniperRifleBuilder = Cast<ACPP_SniperRifleBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Large");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("SniperScope"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Laser"));
		
		Result = SniperRifleBuilder->GetResult();
	}
	else if (auto TacticalRifleBuilder = Cast<ACPP_TacticalRifleBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Default");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("SniperScope"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Laser"));
		
		Result = TacticalRifleBuilder->GetResult();
	}
	else if (auto AssaultRifleBuilder = Cast<ACPP_AssaultRifleBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Default");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("Red Dot"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Flashlight"));
		
		Result = AssaultRifleBuilder->GetResult();
	}
	else if (auto MachineGunBuilder = Cast<ACPP_MachineGunBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Large");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("Red Dot"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Laser"));
		
		Result = MachineGunBuilder->GetResult();
	}
	else if (auto SMGBuilder = Cast<ACPP_SMGBuilder>(Builder->_getUObject()))
	{
		Builder->Execute_SetMagazine(Builder->_getUObject(), "Default");
		Builder->Execute_SetScope(Builder->_getUObject(), TEXT("Red Dot"));
		Builder->Execute_SetAddition(Builder->_getUObject(), TEXT("Laser"));
		
		Result = SMGBuilder->GetResult();
	}

	return Result;
}

ACPP_Weapon* ACPP_WeaponDirector::GetResult()
{
	ACPP_Weapon* Result = nullptr;

	if (auto PistolBuilder = Cast<ACPP_PistolBuilder>(Builder->_getUObject()))
	{
		Result = PistolBuilder->GetResult();
	}
	else if (auto SniperRifleBuilder = Cast<ACPP_SniperRifleBuilder>(Builder->_getUObject()))
	{
		Result = SniperRifleBuilder->GetResult();
	}
	else if (auto TacticalRifleBuilder = Cast<ACPP_TacticalRifleBuilder>(Builder->_getUObject()))
	{
		Result = TacticalRifleBuilder->GetResult();
	}
	else if (auto AssaultRifleBuilder = Cast<ACPP_AssaultRifleBuilder>(Builder->_getUObject()))
	{
		Result = AssaultRifleBuilder->GetResult();
	}
	else if (auto MachineGunBuilder = Cast<ACPP_MachineGunBuilder>(Builder->_getUObject()))
	{
		Result = MachineGunBuilder->GetResult();
	}
	else if (auto SMGBuilder = Cast<ACPP_SMGBuilder>(Builder->_getUObject()))
	{
		Result = SMGBuilder->GetResult();
	}

	return Result;
}

