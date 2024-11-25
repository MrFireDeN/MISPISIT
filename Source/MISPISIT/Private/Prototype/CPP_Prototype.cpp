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

	Initialize(this);
	
	return NewPrototype;
}

void ACPP_Prototype::SetStyle(const FString Name)
{
	// Setting Style of Prototype Subclass

	if (Styles.Contains(Name))
	{
		CurrentStyle = Name;
	}
}

void ACPP_Prototype::Initialize(ACPP_Prototype* Source)
{
	// Initialize class params

	SetStyle(Source->CurrentStyle);
}

