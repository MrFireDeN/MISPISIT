// CPP_Prototype.cpp

#include "Prototype/CPP_Prototype.h"

// Sets default values
ACPP_Prototype::ACPP_Prototype()
{
	PrimaryActorTick.bCanEverTick = false;
}

ACPP_Prototype* ACPP_Prototype::Clone()
{
	if (!GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("World is null, cannot clone actor"));
		
		return nullptr;
	}
	
	ACPP_Prototype* NewPrototype = nullptr;

	CopyPropertiesTo(NewPrototype);
	
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

void ACPP_Prototype::CopyPropertiesTo(ACPP_Prototype*& Target)
{
	// Initialize class params

	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Clone created from CPP_Prototype class"));
		
		Target =
			GetWorld()->SpawnActor<ACPP_Prototype>(ACPP_Prototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}
	
	Target->SetStyle(this->CurrentStyle);
	Target->SetActorLabel(this->GetActorLabel() + "Clone");
}

