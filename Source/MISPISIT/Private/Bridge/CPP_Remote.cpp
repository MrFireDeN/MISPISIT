// CPP_Remote.cpp

#include "Bridge/CPP_Remote.h"

ACPP_Remote::ACPP_Remote()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RemoteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RemoteMesh"));
	RootComponent = RemoteMesh;
	RemoteMesh->SetRelativeScale3D(FVector(0.5));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
	
	UAssetLoader::LoadMeshFromAsset(RemoteMesh, "/Game/Project/Models/Bridge/TV_Pixel/SM_TV_Remote.SM_TV_Remote");
}

void ACPP_Remote::BeginPlay()
{
	Super::BeginPlay();

	if (!Device)
	{
		UE_LOG(LogTemp, Error, TEXT("Device is NULL in BeginPlay"));
		return;
	}
	
	if (Device->Implements<UCPP_IDevice>())
	{
		DeviceInterface = Cast<ICPP_IDevice>(Device);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Device [%s] does NOT implenet ICPP_IDevice interface"), *Device->GetName());
	}
}

bool ACPP_Remote::TogglePower()
{
	if (!DeviceInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	return DeviceInterface->IsEnabled() ? DeviceInterface->Disable() : DeviceInterface->Enable();
}

bool ACPP_Remote::VolumeDown()
{
	if (!DeviceInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!DeviceInterface->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT VolumeDown. Device is DISABLED"));
		return false;
	}

	const int NewVolume = FMath::Clamp(DeviceInterface->GetVolume() - 10, 0, 100);
	return DeviceInterface->SetVolume(NewVolume);
}

bool ACPP_Remote::VolumeUp()
{
	if (!DeviceInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!DeviceInterface->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT VolumeUp. Device is DISABLED"));
		return false;
	}

	const int NewVolume = FMath::Clamp(DeviceInterface->GetVolume() + 10, 0, 100);
	return DeviceInterface->SetVolume(NewVolume);
}

bool ACPP_Remote::ChannelDown()
{
	if (!DeviceInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!DeviceInterface->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT ChannelDown. Device is DISABLED"));;
		return false;
	}

	const int NewChannel = FMath::Clamp(DeviceInterface->GetChannel() - 1, 0 , 3);
	return DeviceInterface->SetChannel(NewChannel);
}

bool ACPP_Remote::ChannelUp()
{
	if (!DeviceInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Device is NULL"));
		return false;
	}

	if (!DeviceInterface->IsEnabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can NOT ChannelUp. Device is DISABLED"));
		return false;
	}

	const int NewChannel = FMath::Clamp(DeviceInterface->GetChannel() + 1, 0 , 3);
	return DeviceInterface->SetChannel(NewChannel);
}