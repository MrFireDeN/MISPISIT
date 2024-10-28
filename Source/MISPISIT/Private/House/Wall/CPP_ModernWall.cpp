// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Wall/CPP_ModernWall.h"


// Sets default values
ACPP_ModernWall::ACPP_ModernWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_ModernWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ModernWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

