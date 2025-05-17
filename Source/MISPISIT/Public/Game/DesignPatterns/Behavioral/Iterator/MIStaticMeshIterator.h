// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIAssetIteratorBase.h"
#include "MIStaticMeshIterator.generated.h"

class UStaticMesh;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIStaticMeshIterator : public UMIAssetIteratorBase
{
	GENERATED_BODY()

public:
	UMIStaticMeshIterator()
	{
		AssetClassFilter = UStaticMesh::StaticClass();
	}
};
