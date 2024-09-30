// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Wall.h"

ACPP_Wall::ACPP_Wall()
{
	Length = 2;
	Width = 2;
	Height = 2;

	SetActorScale3D(FVector(Length, Width, Height));
}

void ACPP_Wall::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(Length, Width, Height));
}
