// CPP_DoorPrototype.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Prototype.h"
#include "CPP_DoorPrototype.generated.h"

UCLASS()
class MISPISIT_API ACPP_DoorPrototype : public ACPP_Prototype
{
	GENERATED_BODY()

public:
	ACPP_DoorPrototype();

protected:
	virtual void CopyPropertiesTo(ACPP_Prototype*& Target) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorFrameMesh;

	TMap<FString, FString> DoorMeshAssetPaths;
	TMap<FString, FString> DoorFrameMeshAssetPaths;

public:
	virtual void SetStyle(const FString Name) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void Toggle();

	UFUNCTION(BlueprintCallable)
	virtual bool IsOpen();
};
