// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Roof.h"

ACPP_Roof::ACPP_Roof()
{
	Length = 2;
	Width = 2;
}

void ACPP_Roof::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(Length, Width, 1));
}
