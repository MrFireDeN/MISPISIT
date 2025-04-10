#include "CPP_FSprayPattern.h"

FCPP_SprayPattern::FCPP_SprayPattern()
{
	FCPP_SprayPattern(0);
}

FCPP_SprayPattern::FCPP_SprayPattern(int32 InSeed, int32 Size)
{
	RandomStream.Initialize(InSeed);
	SprayOffsets.Reserve(Size);
	
	for (int32 i = 0; i < Size; i++)
	{
		float X = RandomStream.FRandRange(1, 3);
		float Y = RandomStream.FRandRange(-1, 1);
		
		SprayOffsets.Add(FVector2D(X, Y));
	}
}

const FVector2D FCPP_SprayPattern::GetSprayOffset(int i) const
{
	if (i >= SprayOffsets.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("Spray Offset is out of range"));
		return FVector2D::ZeroVector;
	}
	
	return SprayOffsets[i];
}

