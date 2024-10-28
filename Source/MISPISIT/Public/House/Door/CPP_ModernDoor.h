// CPP_ModernDoor.h

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Door.h"
#include "CPP_ModernDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_ModernDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	ACPP_ModernDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
