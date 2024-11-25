// CPP_Prototype.cpp

#include "Prototype/CPP_Prototype.h"

// Sets default values
ACPP_Prototype::ACPP_Prototype()
{
	PrimaryActorTick.bCanEverTick = false;
}

ACPP_Prototype* ACPP_Prototype::Clone()
{
	ACPP_Prototype* NewPrototype = nullptr;

	Initialize(NewPrototype);

	if (NewPrototype == nullptr)
	{
		UKismetSystemLibrary::PrintString(this, "NewPrototype is null");
		NewPrototype =
			GetWorld()->SpawnActor<ACPP_Prototype>(ACPP_Prototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}
	
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

void ACPP_Prototype::Initialize(ACPP_Prototype*& Target)
{
	// Initialize class params
	Target->SetStyle(this->CurrentStyle);
	Target->SetActorLabel(this->GetActorLabel() + "Clone");
}

