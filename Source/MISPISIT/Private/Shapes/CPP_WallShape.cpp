// Fill out your copyright notice in the Description page of Project Settings.


#include "Shapes/CPP_WallShape.h"

ACPP_WallShape::ACPP_WallShape()
{
	Length = 2;
	Width = 2;
	Height = 2;
}

void ACPP_WallShape::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(Length, Width, Height));
}
