// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Shape.h"
#include "CPP_PipeShape.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API ACPP_PipeShape : public ACPP_Shape
{
	GENERATED_BODY()

public:
	ACPP_PipeShape();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Dimensions")
	float Height;

public:
	virtual void Draw() override;
};
