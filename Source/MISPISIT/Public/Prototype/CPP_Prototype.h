// CPP_Prototype.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Prototype.generated.h"

UCLASS()
class MISPISIT_API ACPP_Prototype : public AActor
{
	GENERATED_BODY()
	
public:
	ACPP_Prototype();
	
	virtual ACPP_Prototype* Clone();

protected:
	virtual void Initialize();
};
