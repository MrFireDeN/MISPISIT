// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Window/CPP_MedievalWindow.h"


// Sets default values
ACPP_MedievalWindow::ACPP_MedievalWindow()
{
	Name = "Medieval Window";

	// Asset paths
	WindowMeshAssetPath = "/Game/Project/Models/House/Windows/SM_MedievalWindow.SM_MedievalWindow";

	ACPP_Window::InitializeMeshes();
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

