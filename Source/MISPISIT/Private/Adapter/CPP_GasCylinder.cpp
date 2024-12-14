// CPP_GasCylinder.cpp

#include "Adapter/CPP_GasCylinder.h"

#include "WorldPartition/ContentBundle/ContentBundleLog.h"

ACPP_GasCylinder::ACPP_GasCylinder()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	Volume = 1.0;
	Mass = 5.0;
	Modal = 0.028;
}

double ACPP_GasCylinder::GetPressure(const int& Temperature) const
{
	constexpr double R = 8.314;
	return (Mass / Modal) * R * Temperature / Volume;
}

double ACPP_GasCylinder::AmountOfMatter() const
{
	return Mass / Modal;
}

FString ACPP_GasCylinder::ToString() const
{
	return FString::Printf(TEXT("Volume: %.2f m^3. Mass: %.2f kg. Modal: %.3f kg/mol"), Volume, Mass, Modal);
}

bool ACPP_GasCylinder::SetVolume(const double& NewVolume)
{
	if (NewVolume <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("You try to set Volume to %f which NOT possible"), NewVolume);
		return false;
	}

	Volume = NewVolume;
	SetActorScale3D(FVector(FMath::Pow(Volume, 1.0f / 3.0f)));
	return true;
}

bool ACPP_GasCylinder::SetMass(const double& NewMass)
{
	if (NewMass <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("You try to set Mass to %f which NOT possible"), NewMass);
		return false;
	}

	Mass = NewMass;
	return true;
}

bool ACPP_GasCylinder::SetModal(const double& NewModal)
{
	if (NewModal <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("You try to set Modal to %f which NOT possible"), NewModal);
		return false;
	}

	Modal = NewModal;
	return true;
}

