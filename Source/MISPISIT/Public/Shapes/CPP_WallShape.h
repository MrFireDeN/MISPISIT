// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Shape.h"
#include "CPP_WallShape.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_WallShape : public ACPP_Shape
{
	GENERATED_BODY()

public:
	ACPP_WallShape();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Height;
	
public:
	virtual void Draw() override;
};
