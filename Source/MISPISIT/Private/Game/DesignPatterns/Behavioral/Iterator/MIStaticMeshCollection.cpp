// MIStaticMeshCollection.cpp


#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshCollection.h"

#include "Game/DesignPatterns/Behavioral/Iterator/MIAssetIteratorBase.h"
#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshIterator.h"

TScriptInterface<IMIAssetIterator> UMIStaticMeshCollection::CreateIterator_Implementation()
{
	TScriptInterface<IMIAssetIterator> Iterator = NewObject<UMIStaticMeshIterator>(this);

	return Iterator;
}

TArray<FString> UMIStaticMeshCollection::GetAssetRoots_Implementation()
{
	return RootFolders;
}
