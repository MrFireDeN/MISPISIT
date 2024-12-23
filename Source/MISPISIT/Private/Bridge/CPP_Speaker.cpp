// CPP_Speaker.cpp

#include "Bridge/CPP_Speaker.h"

#include "Components/AudioComponent.h"

ACPP_Speaker::ACPP_Speaker()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SpeakerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpeakerMesh"));
	SpeakerBallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpeakerBallMesh"));

	SpeakerMesh->SetupAttachment(RootComponent);
	SpeakerBallMesh->SetupAttachment(SpeakerMesh);

	SpeakerMesh->SetRelativeLocation(FVector(0, 0, 28));
	SpeakerMesh->SetRelativeScale3D(FVector(0.5));

	UAssetLoader::LoadMeshFromAsset(
		SpeakerMesh,
		"/Game/Project/Models/Bridge/Speaker/SM_Speaker.SM_Speaker"
		);

	UAssetLoader::LoadMeshFromAsset(
		SpeakerBallMesh,
		"/Game/Project/Models/Bridge/Speaker/SM_SpeakerSphere.SM_SpeakerSphere"
	);

	SpeakerAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("SpeakerAudio"));
	SpeakerAudio->SetupAttachment(RootComponent);
	
	SetVolume(CurrentVolume);
}

void ACPP_Speaker::BeginPlay()
{
	Super::BeginPlay();
}

bool ACPP_Speaker::IsEnabled()
{
	return !SpeakerBallMesh->GetRelativeRotation().Equals(*SpeakerBallRotations.Find("Disable"));
}

bool ACPP_Speaker::Enable()
{
	if (IsEnabled())
	{
		return true;
	}

	return SetChannel(CurrentChannel);
}

bool ACPP_Speaker::Disable()
{
	if (!IsEnabled())
	{
		return true;
	}

	SpeakerBallMesh->SetRelativeRotation(*SpeakerBallRotations.Find("Disable"));
	SpeakerAudio->Stop();
	return true;
}

int ACPP_Speaker::GetVolume()
{
	return CurrentVolume;
}

bool ACPP_Speaker::SetVolume(const int& NewVolume)
{
	CurrentVolume = FMath::Clamp(NewVolume, 0, 100);

	SpeakerAudio->SetVolumeMultiplier(CurrentVolume / 100);
	
	return true;
}

int ACPP_Speaker::GetChannel()
{
	return CurrentChannel;
}

bool ACPP_Speaker::SetChannel(const int& NewChannel)
{
	CurrentChannel = FMath::Clamp(NewChannel, 0, 2);

	SpeakerAudio->Stop();

	switch (CurrentChannel)
	{
	case 0:
		SpeakerBallMesh->SetRelativeRotation(*SpeakerBallRotations.Find("Channel1"));
		SpeakerAudio->SetSound(SpeakerChannel1);
		break;

	case 1:
		SpeakerBallMesh->SetRelativeRotation(*SpeakerBallRotations.Find("Channel2"));
		SpeakerAudio->SetSound(SpeakerChannel2);
		break;

	case 2:
		SpeakerBallMesh->SetRelativeRotation(*SpeakerBallRotations.Find("Channel3"));
		SpeakerAudio->SetSound(SpeakerChannel3);
		break;

	default:
		break;
	}

	SpeakerAudio->Play();
	
	return true;
}

