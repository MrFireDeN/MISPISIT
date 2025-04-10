#include "CPP_FSprayPattern.h"

/**
 * Default constructor - delegates to parameterized version with seed = 0
 */
FCPP_SprayPattern::FCPP_SprayPattern()
{
	FCPP_SprayPattern(0);
}

/**
 * Initializes spray pattern with specified parameters.
 * Generates deterministic sequence of random recoil offsets.
 * @param InSeed - Seed for random generator
 * @param Size - Number of offsets to generate
 */
FCPP_SprayPattern::FCPP_SprayPattern(int32 InSeed, int32 Size)
{
	RandomStream.Initialize(InSeed);
	SprayOffsets.Reserve(Size);
	
	for (int32 i = 0; i < Size; i++)
	{
		// Generates horizontal spread between 1-3 units
		float X = RandomStream.FRandRange(1, 3);
		// Generates vertical spread between -1 and 1 units
		float Y = RandomStream.FRandRange(-1, 1);
		
		SprayOffsets.Add(FVector2D(X, Y));
	}
}

/**
 * Returns pre-generated spray offset.
 * Safe to call from any thread (const method).
 * @param i - Index of requested offset
 * @return Requested offset or zero vector if invalid index
 */
const FVector2D FCPP_SprayPattern::GetSprayOffset(int i) const
{
	if (i >= SprayOffsets.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("Spray Offset is out of range"));
		return FVector2D::ZeroVector;
	}
	
	return SprayOffsets[i];
}