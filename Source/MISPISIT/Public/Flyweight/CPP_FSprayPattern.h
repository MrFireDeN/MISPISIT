#pragma once

#include "CoreMinimal.h"
#include "CPP_FSprayPattern.generated.h"

USTRUCT(BlueprintType)
struct FCPP_SprayPattern
{
	GENERATED_BODY()

	virtual ~FCPP_SprayPattern() = default;
	FCPP_SprayPattern(int32 InSeed, int32 Size = 1024 * 1024);

	UPROPERTY()
	FRandomStream RandomStream;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Seed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> SprayOffsets;

	virtual FVector2D GetSprayOffset(int i);
};
