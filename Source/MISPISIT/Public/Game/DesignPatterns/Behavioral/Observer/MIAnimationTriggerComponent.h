// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIObserver.h"
#include "Components/ActorComponent.h"
#include "MIAnimationTriggerComponent.generated.h"

class UAnimMontage;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIAnimationTriggerComponent : public UActorComponent, public IMIObserver
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMIAnimationTriggerComponent();

	virtual void OnTimeUpdate_Implementation(int32 NewTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY()
	int32 LastTriggerTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer", meta = (AllowPrivateAccess = "true"))
	int32 AnimationTriggerTime = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> AnimMontage;
};
