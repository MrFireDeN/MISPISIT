// Fill out your copyright notice in the Description page of Project Settings.


#include "Shapes/CPP_DoorShape.h"

ACPP_DoorShape::ACPP_DoorShape()
{
	Width = 0.5;
	Height = 1;
}

void ACPP_DoorShape::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(0.05, Width, Height));
}
