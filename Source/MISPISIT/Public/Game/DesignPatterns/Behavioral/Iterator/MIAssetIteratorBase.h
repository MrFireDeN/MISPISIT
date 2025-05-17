// MIAssetIteratorBase.h

#pragma once

#include "CoreMinimal.h"
#include "MIAssetIterator.h"
#include "UObject/Object.h"
#include "MIAssetIteratorBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MISPISIT_API UMIAssetIteratorBase : public UObject, public IMIAssetIterator
{
	GENERATED_BODY()

public:
	UMIAssetIteratorBase();
	
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

	int32 CurrentIndex = -1;

	void ScanNextStaticMeshFromPath(const FString& Path);
	void ExpandFolder(const FString& FolderPath);
};
