// CPP_TV.cpp

#include "Bridge/CPP_TV.h"

#include "Components/AudioComponent.h"

// Sets default values
ACPP_TV::ACPP_TV()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// TV Meshes
	const TArray<FString> MeshNames = {
		"TV",
		"TV_Button",
		"TV_glass",
		"TV_Reader",
		"TV_Table",
		"TV_VHS",
		"TV_Channel0",
		"TV_Channel1",
		"TV_Channel2",
		"TV_Noise1",
		"TV_Noise2",
		"TV_Noise3",
		"TV_Signal"
	};

	for (auto MeshName : MeshNames)
	{
		UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(*MeshName);
		MeshComponent->SetupAttachment(RootComponent);
		MeshComponent->SetRelativeScale3D(FVector(0.5));
		
		if (MeshName.Contains("Channel"))
		{
			if (MeshName.Contains("0"))
			{
				TV_ScreenMesh = MeshComponent;
			}
			else
			{
				TVChannelMeshes.Add(MeshComponent);
				MeshComponent->SetVisibility(false);
			}
		}
		else if (MeshName.Contains("Noise"))
		{
			TVNoiseMeshes.Add(MeshComponent);
			MeshComponent->SetVisibility(false);
		}
		else if (MeshName.Contains("Signal"))
		{
			TV_SignalMesh = MeshComponent;
			MeshComponent->SetVisibility(false);
		}
		else
		{
			TVMeshes.Add(MeshComponent);
		}

		UAssetLoader::LoadMeshFromAsset(
			MeshComponent,
			FString::Printf(TEXT("/Game/Project/Models/Bridge/TV_Pixel/SM_%s.SM_%s"), *MeshName, *MeshName)
		);
	}

	TVAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("TVAudio"));
	TVAudio->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPP_TV::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_TV::PlayNoiseAnimation()
{
	static int32 CurrentIndex = 0;

	for (auto NoiseMesh : TVNoiseMeshes)
	{
		NoiseMesh->SetVisibility(false);
	}

	TVNoiseMeshes[CurrentIndex]->SetVisibility(true);

	CurrentIndex = (CurrentIndex + 1) % TVNoiseMeshes.Num();
}

// Called every frame
void ACPP_TV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ACPP_TV::IsEnabled()
{
	return !TV_ScreenMesh->IsVisible();
}

bool ACPP_TV::Enable()
{
	if (IsEnabled())
	{
		return true;
	}

	TV_ScreenMesh->SetVisibility(false);
	
	return SetChannel(CurrentChannel);
}

bool ACPP_TV::Disable()
{
	if (!IsEnabled())
	{
		return true;
	}

	for (auto TVChannel : TVChannelMeshes)
	{
		TVChannel->SetVisibility(false);
	}

	for (auto TVNoise : TVNoiseMeshes)
	{
		TVNoise->SetVisibility(false);
	}
	
	GetWorld()->GetTimerManager().ClearTimer(NoiseTimer);

	TV_SignalMesh->SetVisibility(false);

	TV_ScreenMesh->SetVisibility(true);

	if (TVAudio)
	{
		TVAudio->Stop();
	}
	
	return true;
}

int ACPP_TV::GetVolume()
{
	if (!IsEnabled())
	{
		return false;
	}
	
	return CurrentVolume;
}

bool ACPP_TV::SetVolume(const int& NewVolume)
{
	if (!IsEnabled())
	{
		return false;
	}
	
	CurrentVolume = FMath::Clamp(NewVolume, 0, 100);

	if (TVAudio)
	{
		TVAudio->SetVolumeMultiplier(CurrentVolume / 100);
	}
	
	return true;
}

int ACPP_TV::GetChannel()
{
	if (!IsEnabled())
	{
		return false;
	}
	
	return CurrentChannel;
}

bool ACPP_TV::SetChannel(const int& NewChannel)
{
	if (!IsEnabled())
	{
		return false;
	}
	
	CurrentChannel = FMath::Clamp(NewChannel, 0, 3);
	
	for (auto TVChannel : TVChannelMeshes)
	{
		TVChannel->SetVisibility(false);
	}

	for (auto TVNoise : TVNoiseMeshes)
	{
		TVNoise->SetVisibility(false);
	}

	TV_SignalMesh->SetVisibility(false);

	if (TVAudio)
	{
		TVAudio->Stop();
	}

	GetWorld()->GetTimerManager().ClearTimer(NoiseTimer);

	switch (CurrentChannel)
	{
	case 1:
		TVChannelMeshes[0]->SetVisibility(true);

		TVAudio->SetSound(Channel1Sound);
		
		break;
		
	case 2 :
		TVChannelMeshes[1]->SetVisibility(true);

		TVAudio->SetSound(Channel2Sound);
		
		break;
		
	case 3:
		TV_SignalMesh->SetVisibility(true);

		TVAudio->SetSound(SignalSound);
		
		break;
		
	default:
		for (auto TVNoise : TVNoiseMeshes)
		{
			TVNoise->SetVisibility(true);
		}
		
		GetWorld()->GetTimerManager().SetTimer(
			NoiseTimer,
			this,
			&ACPP_TV::PlayNoiseAnimation,
			0.05f,
			true);

		TVAudio->SetSound(NoiseSound);
		
		break;
	}

	TVAudio->Play();
	
	return true;
}

