// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Shape.h"
#include "GameFramework/Actor.h"
#include "CPP_ShapeFabric.generated.h"

UCLASS()
class MISPISIT_API ACPP_ShapeFabric : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_ShapeFabric();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shapes")
	TArray<ACPP_Shape*> Shapes;

	UFUNCTION(BlueprintCallable)
	void Draw(int ShapeIndex);
};
