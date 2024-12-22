// CPP_Speaker.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_IDevice.h"
#include "CPP_Speaker.generated.h"

UCLASS()
class MISPISIT_API ACPP_Speaker : public AActor, public ICPP_IDevice
{
	GENERATED_BODY()

public:
	ACPP_Speaker();

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* SpeakerChannel1;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* SpeakerChannel2;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* SpeakerChannel3;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SpeakerMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SpeakerBallMesh;
	
	int CurrentChannel = 0;
	float CurrentVolume = 50;
	
	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* SpeakerAudio;

	const TMap<FString, FRotator> SpeakerBallRotations = {
		{TEXT("Disable"), FRotator(0)},
		{TEXT("Channel1"), FRotator(0, 90 ,0)},
		{TEXT("Channel2"), FRotator(0, 180, 0)},
		{TEXT("Channel3"), FRotator(0, 270, 0)},
	};
	
public:
	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual bool IsEnabled() override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual bool Enable() override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual bool Disable() override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual int GetVolume() override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual bool SetVolume(const int& NewVolume) override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual int GetChannel() override;

	UFUNCTION(BlueprintCallable, Category = "Speaker")
	virtual bool SetChannel(const int& NewChannel) override;
};
