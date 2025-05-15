// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshIterator_Depth.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshCollection.h"

UMIStaticMeshIterator_Depth::UMIStaticMeshIterator_Depth(const FObjectInitializer& ObjectInitializer)
{
	TArray<FString> RootPaths = {};
	
	if (UMIStaticMeshCollection* Collection = Cast<UMIStaticMeshCollection>(GetOuter()))
	{
		RootPaths = Collection->RootFolders;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[%s]: flied to get Collection"), *GetNameSafe(this))
	}
	
	Stack = RootPaths;
	History.Empty();
	CurrentIndex = -1;
	bNextScanned = false;
	AssetClassFilter = UStaticMesh::StaticClass();
}

UObject* UMIStaticMeshIterator_Depth::GetNext_Implementation()
{
	if (!HasNext()) return nullptr;

	bNextScanned = false;
	++CurrentIndex;
	History.SetNum(CurrentIndex + 1);
	History[CurrentIndex] = CachedNext.Get();
	
	return CachedNext.Get();
}

UObject* UMIStaticMeshIterator_Depth::GetPrevious_Implementation()
{
	if (!HasPrevious()) return nullptr;
	return History[--CurrentIndex];
}

bool UMIStaticMeshIterator_Depth::HasNext_Implementation()
{
	if (bNextScanned) return CachedNext.IsValid();

	while (Stack.Num() > 0)
	{
		FString CurrentPath = Stack.Pop();
		UObject* Found = ScanNextStaticMeshFromPath(CurrentPath);

		if (Found)
		{
			ExpandFolder(CurrentPath);
			CachedNext = Found;
			bNextScanned = true;
			return true;
		}
		else
		{
			ExpandFolder(CurrentPath);
		}
	}

	CachedNext.Reset();
	bNextScanned = false;
	return false;
}

bool UMIStaticMeshIterator_Depth::HasPrevious_Implementation()
{
	return CurrentIndex > 0;
}

void UMIStaticMeshIterator_Depth::Reset_Implementation()
{
	CurrentIndex = -1;
	History.Empty();
	bNextScanned = false;
	CachedNext.Reset();
}

UObject* UMIStaticMeshIterator_Depth::ScanNextStaticMeshFromPath(const FString& Path) const
{
	FAssetRegistryModule& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> Assets;
	AssetRegistry.Get().GetAssetsByPath(FName(*Path), Assets, true);

	for (const FAssetData& Asset : Assets)
	{
		if (Asset.AssetClassPath.ToString() == AssetClassFilter->GetName())
		{
			return Asset.GetAsset();
		}
	}
	
	return nullptr;
}

void UMIStaticMeshIterator_Depth::ExpandFolder(const FString& FolderPath)
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> SubDirs;
	FileManager.FindFilesRecursive(SubDirs, *FolderPath, TEXT("*"), false, true);

	for (int32 i = SubDirs.Num() -1; i >= 0 ; --i)
	{
		Stack.Push(SubDirs[i]);
	}
}
