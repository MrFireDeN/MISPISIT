// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Shape.h"
#include "CPP_Roof.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_Roof : public ACPP_Shape
{
	GENERATED_BODY()

public:
	ACPP_Roof();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Width;

public:
	virtual void Draw() override;
};
