// Fill out your copyright notice in the Description page of Project Settings.


#include "Shapes/CPP_ShapeFabric.h"

// Sets default values
ACPP_ShapeFabric::ACPP_ShapeFabric()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_ShapeFabric::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ShapeFabric::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_ShapeFabric::Draw(int ShapeIndex)
{
	if (Shapes[ShapeIndex])
	{
		Shapes[ShapeIndex]->Draw();
	}
}

