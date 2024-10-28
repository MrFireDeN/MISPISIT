// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CPP_Door.h"
#include "CPP_MedievalDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_MedievalDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_MedievalDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
