// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIEnemy.h"
#include "MIEnemy_Hard.generated.h"

class UMIShieldComponent;
class UMIArmorComponent;

UCLASS()
class MISPISIT_API AMIEnemy_Hard : public AMIEnemy
{
	GENERATED_BODY()

public:
	AMIEnemy_Hard(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE UMIShieldComponent* GetShieldComponent() const { return ShieldComponent; }
	FORCEINLINE UMIArmorComponent* GetArmorComponent() const { return ArmorComponent; }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Enemy: Armor", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIArmorComponent> ArmorComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Enemy: Shield", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIShieldComponent> ShieldComponent;

	virtual void InitializeDamageChain_Implementation() override;
};
