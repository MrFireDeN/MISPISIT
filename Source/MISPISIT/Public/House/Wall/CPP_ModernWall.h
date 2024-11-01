// CPP_ModernWall.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Wall.h"
#include "CPP_ModernWall.generated.h"

UCLASS()
class MISPISIT_API ACPP_ModernWall : public ACPP_Wall
{
	GENERATED_BODY()

public:
	ACPP_ModernWall();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
