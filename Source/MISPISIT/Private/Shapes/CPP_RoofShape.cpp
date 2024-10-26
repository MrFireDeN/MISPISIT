// Fill out your copyright notice in the Description page of Project Settings.


#include "Shapes/CPP_RoofShape.h"

ACPP_RoofShape::ACPP_RoofShape()
{
	Length = 2;
	Width = 2;
}

void ACPP_RoofShape::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(Length, Width, 1));
}
