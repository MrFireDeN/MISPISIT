#pragma once

#include "CoreMinimal.h"
#include "CPP_FSprayPattern.generated.h"

/**
 * Enum defining different types of weapon spray patterns.
 * Used to select or identify specific recoil behaviors.
 */
UENUM(BlueprintType)
enum class ESprayType : uint8
{
	AssaultRifle = 0,  ///< Automatic rifle pattern (moderate horizontal/vertical spread)
	Pistol,            ///< Handgun pattern (tight vertical spread)
	Shotgun,           ///< Shotgun pattern (wide random spread)

	MAX                ///< Sentinel value for iteration
};

/**
 * Structure containing weapon spray pattern data.
 * Implements Flyweight pattern - can be shared between multiple weapon instances.
 */
USTRUCT(BlueprintType)
struct FCPP_SprayPattern
{
	GENERATED_BODY()

	virtual ~FCPP_SprayPattern() = default;
	
	/**
	 * Default constructor (uses seed = 0)
	 */
	FCPP_SprayPattern();
	
	/**
	 * Initializes spray pattern with specific randomization seed
	 * @param InSeed - Seed for deterministic random generation
	 * @param Size - Number of offsets to pre-generate (default 1MB)
	 */
	FCPP_SprayPattern(int32 InSeed, int32 Size = 1024 * 1024);

	/** Random number generator initialized with Seed */
	UPROPERTY()
	FRandomStream RandomStream;

	/** 
	 * Seed value for deterministic pattern generation.
	 * Changing this will produce different spray sequences.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Seed;

	/** Pre-generated sequence of recoil offsets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> SprayOffsets;

	/**
	 * Gets spray offset at specific index
	 * @param i - Index in SprayOffsets array
	 * @return Recoil offset vector (X = horizontal, Y = vertical)
	 * @warning Returns zero vector if index is out of bounds
	 */
	const FVector2D GetSprayOffset(int i) const;
};