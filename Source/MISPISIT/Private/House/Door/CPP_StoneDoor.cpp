// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Door/CPP_StoneDoor.h"


// Sets default values
ACPP_StoneDoor::ACPP_StoneDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_StoneDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_StoneDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

