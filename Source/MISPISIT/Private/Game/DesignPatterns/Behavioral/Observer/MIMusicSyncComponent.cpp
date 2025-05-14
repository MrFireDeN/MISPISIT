// MIMusicSyncComponent.cpp


#include "Game/DesignPatterns/Behavioral/Observer/MIMusicSyncComponent.h"

#include "AssetTypeActions/AssetDefinition_SoundBase.h"
#include "Components/AudioComponent.h"
#include "Game/DesignPatterns/Behavioral/Observer/MITimeServerSubsystem.h"


UMIMusicSyncComponent::UMIMusicSyncComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMIMusicSyncComponent::OnTimeUpdate_Implementation(int32 NewTime)
{
	if (!bIsPlaying && NewTime >= StateTime)
	{
		bIsPlaying = true;
		
		UAudioComponent* AudioComponent = Cast<UAudioComponent>
		(GetOwner()->FindComponentByClass(UAudioComponent::StaticClass()));

		if (AudioComponent)
		{
			AudioComponent->SetSound(Music);
			AudioComponent->Play();
		}
		
		UE_LOG(LogTemp, Display, TEXT("[%s] Play Music"), *GetNameSafe(this));
	}
}

void UMIMusicSyncComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Subscribe(this);
	}
}

void UMIMusicSyncComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Unsubscribe(this);
	}
}

