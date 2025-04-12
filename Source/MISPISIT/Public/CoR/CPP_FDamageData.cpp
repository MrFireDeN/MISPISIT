#include "CPP_FDamageData.h"

FCPP_DamageData::FCPP_DamageData()
{
}

FCPP_DamageData::FCPP_DamageData(
	float Damage,
	TSubclassOf<UDamageType> DamageTypeClass,
	FHitResult HitResult,
	AActor* DamageCauser,
	AController* InstigatorController,
	bool bIsCriticalHit)
{
	this->DamageAmount = Damage;
	this->HitResult = HitResult;
	this->DamageCauser = DamageCauser;
	this->InstigatorController = InstigatorController;
	this->bIsCriticalHit = bIsCriticalHit;
}
