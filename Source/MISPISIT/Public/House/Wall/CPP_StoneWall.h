// CPP_StoneWall.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Wall.h"
#include "CPP_StoneWall.generated.h"

UCLASS()
class MISPISIT_API ACPP_StoneWall : public ACPP_Wall
{
	GENERATED_BODY()

public:
	ACPP_StoneWall();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
