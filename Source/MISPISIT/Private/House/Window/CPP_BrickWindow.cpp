// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_BrickWindow.h"


// Sets default values
ACPP_BrickWindow::ACPP_BrickWindow()
{
	Name = "Brick Window";

	// Asset paths
	WindowMeshAssetPath = "/Game/Project/Models/House/Windows/SM_BrickWindow.SM_BrickWindow";

	ACPP_Window::InitializeMeshes();
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

