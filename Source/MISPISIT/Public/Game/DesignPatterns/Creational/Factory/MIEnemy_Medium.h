// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIEnemy.h"
#include "MIEnemy_Medium.generated.h"

class UMIShieldComponent;

UCLASS()
class MISPISIT_API AMIEnemy_Medium : public AMIEnemy
{
	GENERATED_BODY()

public:
	AMIEnemy_Medium(const FObjectInitializer& ObjectInitializer);
	
	FORCEINLINE UMIShieldComponent* GetShieldComponent() const { return ShieldComponent; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Enemy: Shield", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMIShieldComponent> ShieldComponent;

	virtual void InitializeDamageChain_Implementation() override;
};
