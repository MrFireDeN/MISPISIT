﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_MedievalWindow.h"


// Sets default values
ACPP_MedievalWindow::ACPP_MedievalWindow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_MedievalWindow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MedievalWindow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
