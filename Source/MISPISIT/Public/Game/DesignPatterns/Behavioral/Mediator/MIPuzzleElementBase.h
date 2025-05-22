// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElement.h"
#include "GameFramework/Actor.h"
#include "MIPuzzleElementBase.generated.h"

class UMIPuzzleMediator;

UCLASS(Abstract)
class MISPISIT_API AMIPuzzleElementBase : public AActor, public IMIPuzzleElement
{
	GENERATED_BODY()

public:
	virtual void RegisterWithMediator_Implementation(UMIPuzzleMediator* InMediator) override;
	virtual void NotifyMediator_Implementation(bool State) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mediator")
	TObjectPtr<UMIPuzzleMediator> Mediator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mediator", meta = (AllowPrivateAccess = "true"))
	FName ID;
};
