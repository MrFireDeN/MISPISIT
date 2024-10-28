// CPP_StoneDoor.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Door.h"
#include "CPP_StoneDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_StoneDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	ACPP_StoneDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
