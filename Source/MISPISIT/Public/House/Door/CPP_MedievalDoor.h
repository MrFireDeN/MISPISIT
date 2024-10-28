// CPP_MedievalDoor.h

#pragma once

#include "CoreMinimal.h"
#include "../CPP_Door.h"
#include "CPP_MedievalDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_MedievalDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	ACPP_MedievalDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
