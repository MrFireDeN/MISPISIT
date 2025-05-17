// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIAssetIteratorBase.h"
#include "MIMaterialIterator.generated.h"

class UMaterial;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIMaterialIterator : public UMIAssetIteratorBase
{
	GENERATED_BODY()

public:
	UMIMaterialIterator()
	{
		AssetClassFilter = UMaterial::StaticClass();
	}
};
