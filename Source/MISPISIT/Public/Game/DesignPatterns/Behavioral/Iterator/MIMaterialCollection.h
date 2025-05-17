// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIAssetCollection.h"
#include "UObject/Object.h"
#include "MIMaterialCollection.generated.h"

class IMIAssetIterator;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIMaterialCollection : public UObject, public IMIAssetCollection
{
	GENERATED_BODY()

public:
	virtual TScriptInterface<IMIAssetIterator> CreateIterator_Implementation() override;

	virtual TArray<FString> GetAssetRoots_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Iterator")
	TArray<FString> RootFolders;
};
