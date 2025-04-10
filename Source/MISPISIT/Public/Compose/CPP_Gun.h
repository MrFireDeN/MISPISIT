#pragma once

#include "CoreMinimal.h"
#include "CPP_Product.h"
#include "TraceHelper.h"
#include "Flyweight/CPP_SpraySubsystem.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"
#include "CPP_Gun.generated.h"

/**
 * Base firearm weapon class implementing shooting mechanics and recoil patterns.
 * Uses Flyweight pattern via SpraySubsystem for efficient recoil data sharing.
 */
UCLASS()
class MISPISIT_API ACPP_Gun : public ACPP_Product
{
	GENERATED_BODY()

public:
	ACPP_Gun();

protected:
	virtual void BeginPlay() override;

	/** Helper component for raycasting and hit detection */
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTraceHelper* TraceHelper;

	/** Subsystem managing shared spray patterns (Flyweight pattern) */
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCPP_SpraySubsystem* SpraySubsystem;

	/** Type of weapon spray pattern to use */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	ESprayType SprayType;

	/** Base damage per shot */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float Damage = 50;

	/** Character currently wielding this weapon */
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ACharacter* CharacterOwner;

	/**
	 * Processes firing logic
	 * @param Hit - Valid hit result from trace
	 */
	virtual void Fire(FHitResult Hit);

public:
	//~ Begin ACPP_Product Interface
	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual bool OnPrimaryAction() override;
	//~ End ACPP_Product Interface

private:
	/** Current shot counter for spray pattern sequencing */
	int32 ShotIndex = 0;
};