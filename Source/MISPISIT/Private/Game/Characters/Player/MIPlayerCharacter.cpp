// MIPlayerCharacter.cpp

#include "Game/Characters/Player/MIPlayerCharacter.h"

AMIPlayerCharacter::AMIPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMIPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMIPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMIPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

