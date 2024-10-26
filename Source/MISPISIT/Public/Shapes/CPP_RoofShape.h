// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Shape.h"
#include "CPP_RoofShape.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_RoofShape : public ACPP_Shape
{
	GENERATED_BODY()

public:
	ACPP_RoofShape();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Width;

public:
	virtual void Draw() override;
};
