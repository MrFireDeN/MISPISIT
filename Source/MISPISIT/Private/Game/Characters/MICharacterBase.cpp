// MICharacterBase.cpp

#include "Game/Characters/MICharacterBase.h"


// Sets default values
AMICharacterBase::AMICharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMICharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMICharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMICharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

