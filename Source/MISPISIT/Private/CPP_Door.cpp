// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Door.h"

ACPP_Door::ACPP_Door()
{
	Width = 0.5;
	Height = 1;

	SetActorScale3D(FVector(0.05, Width, Height));
}

void ACPP_Door::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(0.05, Width, Height));
}
