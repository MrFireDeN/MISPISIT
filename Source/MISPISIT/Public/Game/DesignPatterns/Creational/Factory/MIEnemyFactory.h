// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MIEnemyFactory.generated.h"

UENUM(BlueprintType)
enum EEnemyType
{
	Easy,
	Medium,
	Hard
};

class AMIEnemy;

/**
 * 
 */
UCLASS()
class MISPISIT_API AMIEnemyFactory : public AActor
{
	GENERATED_BODY()

public:
	AMIEnemyFactory();

	UFUNCTION(BlueprintCallable, Category = "Factory")
	void Start();

	UFUNCTION(BlueprintCallable, Category = "Factory")
	void Stop();
	
	UFUNCTION(BlueprintCallable, Category="Factory")
	AMIEnemy* CreateEnemy(const EEnemyType EnemyType, const FVector Location);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Factory")
	float SpawnRadius = 300;

	UPROPERTY()
	FTimerHandle TimerHandle;

private:
	void SpawnEnemy();
};
