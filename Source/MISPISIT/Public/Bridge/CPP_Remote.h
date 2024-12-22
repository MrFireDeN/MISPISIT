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

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* RemoteMesh;

	UPROPERTY(EditAnywhere, Category = "Remote")
	AActor* Device;

	ICPP_IDevice* DeviceInterface;

public:
	virtual bool TogglePower();
	virtual bool VolumeDown();
	virtual bool VolumeUp();
	virtual bool ChannelDown();
	virtual bool ChannelUp();
};
