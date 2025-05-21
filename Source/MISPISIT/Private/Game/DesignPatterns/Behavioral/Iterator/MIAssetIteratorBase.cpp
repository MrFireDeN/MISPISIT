// MIAssetIteratorBase.cpp


#include "Game/DesignPatterns/Behavioral/Iterator/MIAssetIteratorBase.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Game/DesignPatterns/Behavioral/Iterator/MIStaticMeshCollection.h"

UMIAssetIteratorBase::UMIAssetIteratorBase()
{
	TArray<FString> RootPaths = {};
	
	if (TScriptInterface<IMIAssetCollection> Collection = GetOuter())
	{
		RootPaths = Collection->Execute_GetAssetRoots(Collection.GetObject());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[%s]: flied to get Collection"), *GetNameSafe(this))
	}
	
	Stack = RootPaths;
	History.Empty();
	CurrentIndex = -1;
}

UObject* UMIAssetIteratorBase::GetNext_Implementation()
{
	if (!History.IsEmpty() && CurrentIndex < History.Num() - 1)
	{
		return History[++CurrentIndex];
	}

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

UObject* UMIAssetIteratorBase::GetPrevious_Implementation()
{
	if (!Execute_HasPrevious(this)) return nullptr;
	--CurrentIndex;
	
	return History[CurrentIndex];
}

bool UMIAssetIteratorBase::HasNext_Implementation()
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
		FillPendingAssetsFromPath(CurrentPath);
		
		if (!PendingAssets.IsEmpty())
		{
			return true;
		}
	}
	
	return false;
}

bool UMIAssetIteratorBase::HasPrevious_Implementation()
{
	return CurrentIndex > 0;
}

void UMIAssetIteratorBase::Reset_Implementation()
{
	CurrentIndex = -1;
	History.Empty();
}

void UMIAssetIteratorBase::FillPendingAssetsFromPath(const FString& Path)
{
	if (!AssetClassFilter) {
		UE_LOG(LogTemp, Error, TEXT("[%s]: AssetClassFilter is NOT valid"), *GetNameSafe(this))
		return;
	}
	
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

void UMIAssetIteratorBase::ExpandFolder(const FString& FolderPath)
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> SubDirs;
	FileManager.FindFilesRecursive(SubDirs, *FolderPath, TEXT("*"), false, true);

	for (int32 i = SubDirs.Num() -1; i >= 0 ; --i)
	{
		Stack.Push(SubDirs[i]);
	}
}
