// CPP_TV.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_IDevice.h"
#include "CPP_TV.generated.h"

UCLASS()
class MISPISIT_API ACPP_TV : public AActor, public ICPP_IDevice
{
	GENERATED_BODY()

public:
	ACPP_TV();

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* NoiseSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* SignalSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* Channel1Sound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* Channel2Sound;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	TArray<UStaticMeshComponent*> TVMeshes;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TArray<UStaticMeshComponent*> TVChannelMeshes;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TArray<UStaticMeshComponent*> TVNoiseMeshes;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* TV_SignalMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* TV_ScreenMesh;

	int CurrentChannel = 0;
	float CurrentVolume = 50;

	FTimerHandle NoiseTimer;
	virtual void PlayNoiseAnimation();

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* TVAudio;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual bool IsEnabled() override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual bool Enable() override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual bool Disable() override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual int GetVolume() override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual bool SetVolume(const int& NewVolume) override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual int GetChannel() override;

	UFUNCTION(BlueprintCallable, Category = "TV")
	virtual bool SetChannel(const int& NewChannel) override;
};
