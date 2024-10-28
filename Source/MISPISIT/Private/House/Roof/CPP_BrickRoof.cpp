// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Roof/CPP_BrickRoof.h"


// Sets default values
ACPP_BrickRoof::ACPP_BrickRoof()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_BrickRoof::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BrickRoof::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

