// MICharacterMovementComponent.cpp

#include "Game/Characters/Components/MICharacterMovementComponent.h"


UMICharacterMovementComponent::UMICharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMICharacterMovementComponent::StartSprinting()
{
	if (CanSprint() && !bIsSprinting)
	{
		bIsSprinting = true;
		MaxWalkSpeed = SprintSpeed;
	}
}

void UMICharacterMovementComponent::StopSprinting()
{
	bIsSprinting = false;
	MaxWalkSpeed = WalkSpeed;
}

bool UMICharacterMovementComponent::CanSprint() const
{
	return IsMovingOnGround() && !IsCrouching();
}

void UMICharacterMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
	MaxWalkSpeed = WalkSpeed;
}

void UMICharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsSprinting && Velocity.SizeSquared() < KINDA_SMALL_NUMBER)
	{
		StopSprinting();
	}
}

