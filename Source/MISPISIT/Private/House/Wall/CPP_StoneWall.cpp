﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Wall/CPP_StoneWall.h"


// Sets default values
ACPP_StoneWall::ACPP_StoneWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_StoneWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_StoneWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
