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
	if (!Execute_HasNext(this)) return nullptr;

	UObject* NextAsset = nullptr;
	PendingAssets.Dequeue(NextAsset);
	
	if (NextAsset != nullptr)
	{
		++CurrentIndex;
		History.SetNum(CurrentIndex + 1);
		History[CurrentIndex] = NextAsset;
	}

	return NextAsset;
}

UObject* UMIStaticMeshIterator_Depth::GetPrevious_Implementation()
{
	if (!Execute_HasPrevious(this)) return nullptr;
	--CurrentIndex;
	
	return History[CurrentIndex];
}

bool UMIStaticMeshIterator_Depth::HasNext_Implementation()
{
	if (!PendingAssets.IsEmpty())
	{
		return true;
	}

	while (Stack.Num() > 0)
	{
		FString CurrentPath = Stack.Pop();

		if (VisitedPaths.Contains(CurrentPath))
			continue;

		VisitedPaths.Add(CurrentPath);
		ExpandFolder(CurrentPath);
		ScanNextStaticMeshFromPath(CurrentPath);
		
		if (!PendingAssets.IsEmpty())
		{
			return true;
		}
	}
	
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

void UMIStaticMeshIterator_Depth::ScanNextStaticMeshFromPath(const FString& Path)
{
	FAssetRegistryModule& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	
	TArray<FAssetData> Assets;
	AssetRegistry.Get().GetAssetsByPath(FName(*Path), Assets, true);

	for (const FAssetData& Asset : Assets)
	{
		if (Asset.GetClass() == AssetClassFilter.Get())
		{
			if (UObject* LoadedAsset = Asset.GetAsset())
			{
				PendingAssets.Enqueue(LoadedAsset);
			}
		}
	}
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
