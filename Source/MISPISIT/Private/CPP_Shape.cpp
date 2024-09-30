// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Shape.h"

// Sets default values
ACPP_Shape::ACPP_Shape()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	StaticMesh->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void ACPP_Shape::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Shape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Shape::Draw()
{
	StaticMesh->SetHiddenInGame(bIsActive());
	
	if (bIsActive())
	{
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

bool ACPP_Shape::bIsActive()
{
	return !StaticMesh->bHiddenInGame;
}

