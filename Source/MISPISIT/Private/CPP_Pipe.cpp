// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Pipe.h"

ACPP_Pipe::ACPP_Pipe()
{
	Height = 1;
}

void ACPP_Pipe::Draw()
{
	Super::Draw();

	SetActorScale3D(FVector(0.25, 0.25, Height));
}
