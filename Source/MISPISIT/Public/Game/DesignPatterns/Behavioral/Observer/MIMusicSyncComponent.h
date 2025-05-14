// MIMusicSyncComponent.h

#pragma once

#include "CoreMinimal.h"
#include "MIObserver.h"
#include "Components/ActorComponent.h"
#include "MIMusicSyncComponent.generated.h"

class USoundBase;
class UAudioComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIMusicSyncComponent : public UActorComponent, public IMIObserver
{
	GENERATED_BODY()

public:
	UMIMusicSyncComponent();

	virtual void OnTimeUpdate_Implementation(int32 NewTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer", meta = (AllowPrivateAccess = "true"))
	int32 StateTime = 20;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Observer", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USoundBase> Music;

private:
	bool bIsPlaying = false;
};
