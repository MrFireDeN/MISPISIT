// MIStaticMeshCollection.cpp


#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshCollection.h"

#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshIterator_Depth.h"

TScriptInterface<IMIAssetIterator> UMIStaticMeshCollection::CreateIterator_Implementation()
{
	TScriptInterface<IMIAssetIterator> Iterator = NewObject<UMIStaticMeshIterator_Depth>(this);

	return Iterator;
}
