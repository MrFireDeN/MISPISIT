// MIPlayerCharacter.cpp

#include "Game/Characters/Player/MIPlayerCharacter.h"


// Sets default values
AMIPlayerCharacter::AMIPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMIPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMIPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMIPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

