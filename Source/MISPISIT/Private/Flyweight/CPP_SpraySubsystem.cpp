#include "Flyweight/CPP_SpraySubsystem.h"

/**
 * Returns shared spray pattern data for requested weapon type
 * @param Type - Weapon type from ESprayType enum
 * @return Const pointer to pattern data or nullptr for invalid requests
 */
const FCPP_SprayPattern* UCPP_SpraySubsystem::GetSprayPattern(const ESprayType Type) const
{
	if (Type == ESprayType::MAX)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to access invalid spray type MAX"));
		return nullptr;
	}

	return SprayPatterns[static_cast<uint32>(Type)].Get();
}

/**
 * Initializes spray patterns for all weapon types.
 * Uses different seeds for each pattern to ensure variation:
 * - Assault Rifle: Seed 1 (moderate spread)
 * - Pistol: Seed 2 (tight spread) 
 * - Shotgun: Seed 3 (wide spread)
 */
void UCPP_SpraySubsystem::PostInitialize()
{
	Super::PostInitialize();
    
	// Pre-allocate memory for all patterns
	SprayPatterns.Reserve(Count);

	// Generate patterns for each weapon type
	for (uint8 i = 0; i < Count; ++i)
	{
		const ESprayType CurrentType = static_cast<ESprayType>(i);
    
		switch (CurrentType)
		{
		case ESprayType::AssaultRifle:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(1));
			UE_LOG(LogTemp, Verbose, TEXT("Created assault rifle spray pattern"));
			break;
                
		case ESprayType::Pistol:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(2));
			UE_LOG(LogTemp, Verbose, TEXT("Created pistol spray pattern"));
			break;
                
		case ESprayType::Shotgun:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(3));
			UE_LOG(LogTemp, Verbose, TEXT("Created shotgun spray pattern"));
			break;
                
		default:
			UE_LOG(LogTemp, Error, TEXT("Unhandled spray type in initialization"));
			break;
		}
	}
}