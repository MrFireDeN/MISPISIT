// CPP_Prototype.cpp

#include "Prototype/CPP_Prototype.h"

// Sets default values
ACPP_Prototype::ACPP_Prototype()
{
	PrimaryActorTick.bCanEverTick = false;
}

ACPP_Prototype* ACPP_Prototype::Clone()
{
	ACPP_Prototype* NewPrototype = GetWorld()->SpawnActor<ACPP_Prototype>(GetClass());

	Initialize();
	
	return NewPrototype;
}

void ACPP_Prototype::Initialize()
{
	// Initialize class params
}

