// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_BrickWindow.h"


// Sets default values
ACPP_BrickWindow::ACPP_BrickWindow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_BrickWindow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BrickWindow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

