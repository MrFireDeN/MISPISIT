// MIStaticMeshCollection.h

#pragma once

#include "CoreMinimal.h"
#include "MIAssetCollection.h"
#include "UObject/Object.h"
#include "MIStaticMeshCollection.generated.h"

class IMIAssetIterator;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIStaticMeshCollection : public UObject, public IMIAssetCollection
{
	GENERATED_BODY()

public:
	virtual TScriptInterface<IMIAssetIterator> CreateIterator_Implementation() override;

	virtual TArray<FString> GetAssetRoots_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Iterator")
	TArray<FString> RootFolders;
};
