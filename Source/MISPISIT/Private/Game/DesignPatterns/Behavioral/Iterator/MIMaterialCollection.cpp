// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Iterator/MIMaterialCollection.h"

#include "Game/DesignPatterns/Behavioral/Iterator/MIMaterialIterator.h"

TScriptInterface<IMIAssetIterator> UMIMaterialCollection::CreateIterator_Implementation()
{
	TScriptInterface<IMIAssetIterator> Iterator = NewObject<UMIMaterialIterator>(this);

	return Iterator;
}

TArray<FString> UMIMaterialCollection::GetAssetRoots_Implementation()
{
	return RootFolders;
}
