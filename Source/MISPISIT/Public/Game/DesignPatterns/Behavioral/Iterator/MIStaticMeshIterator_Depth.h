// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIAssetIterator.h"
#include "UObject/Object.h"
#include "MIStaticMeshIterator_Depth.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIStaticMeshIterator_Depth : public UObject, public IMIAssetIterator
{
	GENERATED_BODY()

public:
	UMIStaticMeshIterator_Depth(const FObjectInitializer& ObjectInitializer);
	
	virtual UObject* GetNext_Implementation() override;
	virtual UObject* GetPrevious_Implementation() override;
	
	virtual bool HasNext_Implementation() override;
	virtual bool HasPrevious_Implementation() override;
	
	virtual void Reset_Implementation() override;

protected:
	UPROPERTY()
	TArray<FString> Stack;
	
	UPROPERTY()
	TArray<UObject*> History;

	TQueue<UObject*> PendingAssets;

	UPROPERTY()
	TSubclassOf<UObject> AssetClassFilter;

	UPROPERTY()
	TSet<FString> VisitedPaths;
	
	TWeakObjectPtr<UObject> CachedNext = nullptr;
	mutable bool bNextScanned = false;

	int32 CurrentIndex = -1;

	void ScanNextStaticMeshFromPath(const FString& Path);
	void ExpandFolder(const FString& FolderPath);
};
