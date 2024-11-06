// CPP_Door.cpp

#include "House/CPP_Door.h"

/**
 * @brief Toggles the door's state between open and closed, with a message indicating the new state.
 * 
 * Calls IsOpen() to check the current state. If the door is open, it prints "Door closed"; if closed,
 * it prints "Door opened". Override this function to implement actual door state tracking.
 */
void ACPP_Door::Toggle()
{
	if (IsOpen())
	{
		UKismetSystemLibrary::PrintString(this, Name + ": closed");
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, Name + ": opened");
	}
}

/**
 * @brief Returns whether the door is open. 
 * 
 * Default implementation always returns false, meaning the door is closed.
 * Override this function to return the actual state of the door.
 * 
 * @return false, indicating the door is closed by default.
 */
bool ACPP_Door::IsOpen()
{
	return false;
}

void ACPP_Door::InitializeMeshes()
{
	// Component creation and attachment
	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorFrameMesh;
	DoorMesh->SetupAttachment(DoorFrameMesh);

	// Door frame setup
	const FVector DoorFrameSize(30.0f);
	DoorFrameMesh->SetWorldScale3D(DoorFrameSize);

	// Door setup with relative scale and location
	const FVector DoorScale(1.0f / 30.0f);
	const FVector DoorLocation(94.94f / 30.0f, -4.97f / 30.0f, 0.0f);
	DoorMesh->SetRelativeScale3D(DoorScale);
	DoorMesh->SetRelativeLocation(DoorLocation);

	// Load and assign meshes
	if (!LoadMeshFromAsset(DoorFrameMesh, DoorFrameMeshAssetPath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load DoorFrameMesh from %s"), *DoorFrameMeshAssetPath);
	}
    
	if (!LoadMeshFromAsset(DoorMesh, DoorMeshAssetPath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load DoorMesh from %s"), *DoorMeshAssetPath);
	}
}
