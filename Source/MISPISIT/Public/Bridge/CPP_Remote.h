// CPP_Remote.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_IDevice.h"
#include "CPP_Remote.generated.h"

UCLASS()
class MISPISIT_API ACPP_Remote : public AActor
{
	GENERATED_BODY()

public:
	ACPP_Remote();

protected:
	UStaticMeshComponent* RemoteMesh;
	ICPP_IDevice* Device;

	virtual bool Connect(ICPP_IDevice*& Target);

public:
	virtual bool TogglePower();
	virtual bool VolumeDown();
	virtual bool VolumeUp();
	virtual bool ChannelDown();
	virtual bool ChannelUp();
};
