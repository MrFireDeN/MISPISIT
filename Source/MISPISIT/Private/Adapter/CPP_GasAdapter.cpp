// CPP_GasAdapter.cpp

#include "Adapter/CPP_GasAdapter.h"

UCPP_GasAdapter::UCPP_GasAdapter()
{
}

bool UCPP_GasAdapter::Initialize(ACPP_GasCylinder* InCylinder)
{
	if (!InCylinder)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Cylinder"));
		return false;
	}

	GasCylinder = InCylinder;
	return true;
}

double UCPP_GasAdapter::CalculateDp(const int& T0, const int& dT)
{
	double P0 = GasCylinder->GetPressure(T0);
	double P1 = GasCylinder->GetPressure(T0 + dT);
	
	return P0 + P1;
}

bool UCPP_GasAdapter::ModifMass(const double& dm)
{
	const double NewMass = GasCylinder->GetMass() + dm;
	
	return GasCylinder->SetMass(NewMass);
}

bool UCPP_GasAdapter::ModifVolume(const double& dV)
{
	const double NewVolume = GasCylinder->GetVolume() + dV;
	
	return GasCylinder->SetVolume(NewVolume);
}

FString UCPP_GasAdapter::GetData()
{
	return GasCylinder->ToString();
}
