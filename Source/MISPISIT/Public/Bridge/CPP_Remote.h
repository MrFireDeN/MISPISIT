// CPP_Remote.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_IDevice.h"
#include "CPP_Interactable.h"
#include "Components/BoxComponent.h"
#include "CPP_Remote.generated.h"

UCLASS()
class MISPISIT_API ACPP_Remote : public AActor, public ICPP_Interactable
{
	GENERATED_BODY()

public:
	ACPP_Remote();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* RemoteMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, Category = "Remote")
	AActor* Device;

	ICPP_IDevice* DeviceInterface;

public:
	UFUNCTION(BlueprintCallable, Category = "Remote")
	virtual bool TogglePower();
	
	UFUNCTION(BlueprintCallable, Category = "Remote")
	virtual bool VolumeDown();
	
	UFUNCTION(BlueprintCallable, Category = "Remote")
	virtual bool VolumeUp();
	
	UFUNCTION(BlueprintCallable, Category = "Remote")
	virtual bool ChannelDown();
	
	UFUNCTION(BlueprintCallable, Category = "Remote")
	virtual bool ChannelUp();
	
	virtual bool OnNumericAction(const int Digit) override;

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
};
