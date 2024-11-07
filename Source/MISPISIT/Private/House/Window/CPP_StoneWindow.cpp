// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_StoneWindow.h"


// Sets default values
ACPP_StoneWindow::ACPP_StoneWindow()
{
	Name = "Stone Window";

	// Asset paths
	WindowMeshAssetPath = "/Game/Project/Models/House/Windows/SM_StoneWindow.SM_StoneWindow";

	ACPP_Window::InitializeMeshes();
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

