// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Product.h"
#include "TraceHelper.h"
#include "Flyweight/CPP_SpraySubsystem.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"
#include "CPP_Gun.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_Gun : public ACPP_Product
{
	GENERATED_BODY()

	ACPP_Gun();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTraceHelper* TraceHelper;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCPP_SpraySubsystem* SpraySubsystem;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	ESprayType SprayType;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float Damage = 50;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ACharacter* CharacterOwner;

	virtual void Fire(FHitResult Hit);

public:
	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual bool OnPrimaryAction() override;

private:
	int32 ShotIndex = 0;
};
