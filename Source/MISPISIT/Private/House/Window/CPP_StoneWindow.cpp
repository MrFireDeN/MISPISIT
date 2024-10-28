// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_StoneWindow.h"


// Sets default values
ACPP_StoneWindow::ACPP_StoneWindow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_StoneWindow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_StoneWindow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

