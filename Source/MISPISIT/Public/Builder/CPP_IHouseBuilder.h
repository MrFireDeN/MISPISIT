// CPP_IHouseBuilder.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_IHouseBuilder.generated.h"

UINTERFACE()
class UCPP_IHouseBuilder : public UInterface
{
	GENERATED_BODY()
};
class MISPISIT_API ICPP_IHouseBuilder
{
	GENERATED_BODY()

public:
	virtual void SetWalls(int Length, int Width) = 0;

	virtual void SetDoors(int Count) = 0;

	virtual void SetWindows(int Count) = 0;

	virtual void SetRoof(int Height) = 0;

	virtual void Reset() = 0;
};
