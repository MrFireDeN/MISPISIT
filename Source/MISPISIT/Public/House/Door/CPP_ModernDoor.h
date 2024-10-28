// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Door.h"
#include "CPP_ModernDoor.generated.h"

UCLASS()
class MISPISIT_API ACPP_ModernDoor : public ACPP_Door
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_ModernDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
