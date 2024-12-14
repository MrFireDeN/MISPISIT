// CPP_GasCylinder.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_GasCylinder.generated.h"

UCLASS()
class MISPISIT_API ACPP_GasCylinder : public AActor
{
	GENERATED_BODY()

public:
	ACPP_GasCylinder();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual double GetPressure(const int& Temperature) const;
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual double AmountOfMatter() const;
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual FString ToString() const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gas Properties")
	double Volume; // m^3

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gas Properties")
	double Mass; // kg

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gas Properties")
	double Modal; // kg/mol

public:
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual bool SetVolume(const double& NewVolume);
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual bool SetMass(const double& NewMass);
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual bool SetModal(const double& NewModal);
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual double GetVolume() const { return Volume; }
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual double GetMass() const { return Mass; }
	
	UFUNCTION(BlueprintCallable, Category = "Gas")
	virtual double GetModal() const { return Modal; }
};
