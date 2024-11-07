// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_ModernWindow.h"


// Sets default values
ACPP_ModernWindow::ACPP_ModernWindow()
{
	Name = "Modern Window";

	// Asset paths
	WindowMeshAssetPath = "/Game/Project/Models/House/Windows/SM_ModernWindow.SM_ModernWindow";

	ACPP_Window::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_ModernWindow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ModernWindow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

