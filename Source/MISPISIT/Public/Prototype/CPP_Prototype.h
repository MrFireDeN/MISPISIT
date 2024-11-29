// CPP_Prototype.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../House/CPP_BuildingFactory.h"
#include "CPP_Prototype.generated.h"

UCLASS()
class MISPISIT_API ACPP_Prototype : public AActor
{
	GENERATED_BODY()
	
public:
	ACPP_Prototype();

	UFUNCTION(BlueprintCallable)
	virtual ACPP_Prototype* Clone();

	UFUNCTION(BlueprintCallable)
	virtual void SetStyle(const FString Name);

protected:
	TArray<FString> Styles = {"Medieval", "Stone", "Brick", "Modern"};
	
	FString CurrentStyle = Styles[0];
	
	virtual void CopyPropertiesTo(ACPP_Prototype*& Target);
};
