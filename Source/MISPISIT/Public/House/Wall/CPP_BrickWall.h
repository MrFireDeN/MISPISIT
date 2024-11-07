// CPP_BrickWall.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Wall.h"
#include "CPP_BrickWall.generated.h"

UCLASS()
class MISPISIT_API ACPP_BrickWall : public ACPP_Wall
{
	GENERATED_BODY()

public:
	ACPP_BrickWall();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
