#pragma once

#include "CoreMinimal.h"
#include "CPP_FSprayPattern.generated.h"

UENUM(BlueprintType)
enum class ESprayType : uint8
{
	AssaultRifle = 0,
	Pistol,
	Shotgun,

	MAX
};

USTRUCT(BlueprintType)
struct FCPP_SprayPattern
{
	GENERATED_BODY()

	virtual ~FCPP_SprayPattern() = default;
	FCPP_SprayPattern();
	FCPP_SprayPattern(int32 InSeed, int32 Size = 1024 * 1024);

	UPROPERTY()
	FRandomStream RandomStream;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Seed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> SprayOffsets;

	const FVector2D GetSprayOffset(int i) const;
};
