// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Roof.h"
#include "CPP_StoneRoof.generated.h"

UCLASS()
class MISPISIT_API ACPP_StoneRoof : public ACPP_Roof
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_StoneRoof();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
