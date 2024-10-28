// CPP_BrickDoor.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Door.h"
#include "CPP_BrickDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_BrickDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	ACPP_BrickDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
