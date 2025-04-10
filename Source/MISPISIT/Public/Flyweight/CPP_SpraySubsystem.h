#pragma once

#include "CoreMinimal.h"
#include "CPP_FSprayPattern.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_SpraySubsystem.generated.h"

/**
 * World Subsystem for managing and sharing weapon spray patterns.
 * Implements Flyweight pattern to efficiently reuse spray pattern data across multiple weapons.
 * 
 * Initialized automatically when the world loads and destroyed when world transitions.
 */
UCLASS()
class MISPISIT_API UCPP_SpraySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Retrieves spray pattern for specified weapon type
	 * @param Type - Weapon type to get pattern for
	 * @return Shared pointer to spray pattern data (nullptr if invalid type)
	 * @note Thread-safe read operation
	 */
	const FCPP_SprayPattern* GetSprayPattern(const ESprayType Type) const;

protected:
	/**
	 * Initializes subsystem and pre-generates all spray patterns
	 * @warning Called during world initialization - avoid expensive operations
	 */
	virtual void PostInitialize() override;

private:
	/** Number of spray patterns to store (matches ESprayType::MAX) */
	uint8 Count = static_cast<uint8>(ESprayType::MAX);
    
	/** Pre-allocated array of spray patterns using inline allocation */
	TArray<TSharedPtr<FCPP_SprayPattern>, TInlineAllocator<3>> SprayPatterns;
};