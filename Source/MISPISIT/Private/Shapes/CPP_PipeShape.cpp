// Fill out your copyright notice in the Description page of Project Settings.


#include "Shapes/CPP_PipeShape.h"

ACPP_PipeShape::ACPP_PipeShape()
{
	Height = 1;
}

void ACPP_PipeShape::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(0.25, 0.25, Height));
}
