// CPP_GasAdapter.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CPP_GasCylinder.h"
#include "CPP_IGasAdapter.h"
#include "CPP_GasAdapter.generated.h"

UCLASS(BlueprintType)
class MISPISIT_API UCPP_GasAdapter : public UObject, public ICPP_IGasAdapter
{
	GENERATED_BODY()

private:
	ACPP_GasCylinder* GasCylinder;

public:
	virtual bool Initialize(ACPP_GasCylinder*& InCylinder);

	UFUNCTION(BlueprintCallable, Category = "Gas Adapter")
	virtual double CalculateDp(const int& T0, const int& dT) override;

	UFUNCTION(BlueprintCallable, Category = "Gas Adapter")
	virtual bool ModifMass(const double& dm) override;

	UFUNCTION(BlueprintCallable, Category = "Gas Adapter")
	virtual bool ModiVolume(const double& dV) override;

	UFUNCTION(BlueprintCallable, Category = "Gas Adapter")
	virtual FString GetData() override;
};
