// CPP_MedievalWall.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Wall.h"
#include "CPP_MedievalWall.generated.h"

UCLASS()
class MISPISIT_API ACPP_MedievalWall : public ACPP_Wall
{
	GENERATED_BODY()

public:
	ACPP_MedievalWall();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
