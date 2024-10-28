// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "House/CPP_Window.h"
#include "CPP_ModernWindow.generated.h"

UCLASS()
class MISPISIT_API ACPP_ModernWindow : public ACPP_Window
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_ModernWindow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
