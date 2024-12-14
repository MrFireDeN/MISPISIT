// CPP_IGasAdapter.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_IGasAdapter.generated.h"

UINTERFACE()
class UCPP_IGasAdapter : public UInterface
{
	GENERATED_BODY()
};

class MISPISIT_API ICPP_IGasAdapter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual double CalculateDp(const int& T0, const int& dT) = 0;
	virtual bool ModifMass(const double& dm) = 0;
	virtual bool ModifVolume(const double& dV) = 0;
	virtual FString GetData() = 0;
};
