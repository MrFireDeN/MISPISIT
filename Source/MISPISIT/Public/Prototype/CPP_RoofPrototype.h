// CPP_RoofPrototype.cpp

#pragma once

#include "CoreMinimal.h"
#include "CPP_Prototype.h"
#include "CPP_RoofPrototype.generated.h"

UCLASS()
class MISPISIT_API ACPP_RoofPrototype : public ACPP_Prototype
{
	GENERATED_BODY()

public:
	ACPP_RoofPrototype();

protected:
	virtual void CopyPropertiesTo(ACPP_Prototype*& Target) override;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* RoofMesh;
	
	TMap<FString, FString> RoofMeshAssetPaths;

public:
	virtual void SetStyle(const FString Name) override;
};
