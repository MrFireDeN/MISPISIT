// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Door/CPP_ModernDoor.h"


// Sets default values
ACPP_ModernDoor::ACPP_ModernDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_ModernDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ModernDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

