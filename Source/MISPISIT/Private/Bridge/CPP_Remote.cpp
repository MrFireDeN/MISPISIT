// CPP_Remote.cpp

#include "Bridge/CPP_Remote.h"

ACPP_Remote::ACPP_Remote()
{
	RemoteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RemoteMesh"));
	RootComponent = RemoteMesh;
	
	UAssetLoader::LoadMeshFromAsset(RemoteMesh, "/Game/Project/Models/Bridge/TV_Pixel/SM_TV_Remote.SM_TV_Remote");
}

bool ACPP_Remote::Connect(ICPP_IDevice*& Target)
{
	if (!Target)
	{
		UE_LOG(LogTemp, Error, TEXT("Target Device is NULL"));
		return false;
	}
	
	Device = Target;
	
	return true;
}

bool ACPP_Remote::TogglePower()
{
	if (!Device)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	return Device->IsEnabled() ? Device->Disable() : Device->Enable();
}

bool ACPP_Remote::VolumeDown()
{
	if (!Device)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!Device->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT VolumeDown. Device is DISABLED"));
		return false;
	}

	const int NewVolume = FMath::Clamp(Device->GetVolume() - 10, 0, 100);
	return Device->SetVolume(NewVolume);
}

bool ACPP_Remote::VolumeUp()
{
	if (!Device)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!Device->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT VolumeUp. Device is DISABLED"));
		return false;
	}

	const int NewVolume = FMath::Clamp(Device->GetVolume() + 10, 0, 100);
	return Device->SetVolume(NewVolume);
}

bool ACPP_Remote::ChannelDown()
{
	if (!Device)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!Device->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT ChannelDown. Device is DISABLED"));;
		return false;
	}

	const int NewChannel = FMath::Clamp(Device->GetChannel() - 1, 0 , 3);
	return Device->SetChannel(NewChannel);
}

bool ACPP_Remote::ChannelUp()
{
	if (!Device)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!Device->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT ChannelUp. Device is DISABLED"));
		return false;
	}

	const int NewChannel = FMath::Clamp(Device->GetChannel() + 1, 0 , 3);
	return Device->SetChannel(NewChannel);
}