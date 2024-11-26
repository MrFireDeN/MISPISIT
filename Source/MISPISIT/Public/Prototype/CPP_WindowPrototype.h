// CPP_WindowPrototype.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Prototype.h"
#include "CPP_WindowPrototype.generated.h"

UCLASS()
class MISPISIT_API ACPP_WindowPrototype : public ACPP_Prototype
{
	GENERATED_BODY()

public:
	ACPP_WindowPrototype();

protected:
	virtual void CopyPropertiesTo(ACPP_Prototype*& Target) override;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* WindowMesh;

	TMap<FString, FString> WindowMeshAssetPaths;
	
public:
	UFUNCTION(BlueprintCallable)
	virtual void ToggleLight();

	UFUNCTION(BlueprintCallable)
	virtual bool IsLightOn();
	
	virtual void SetStyle(const FString Name) override;
};
