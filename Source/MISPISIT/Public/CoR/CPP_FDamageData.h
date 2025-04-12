#pragma once

#include "CoreMinimal.h"
#include "CPP_FDamageData.generated.h"

USTRUCT(BlueprintType)
struct FCPP_DamageData
{
	GENERATED_BODY()

	FCPP_DamageData();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float DamageAmount = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	AActor* DamageCauser = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	AController* InstigatorController = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	FHitResult HitResult;

	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	bool bIsCriticalHit = false;
};
