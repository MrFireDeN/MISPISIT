// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Command/MIMoveToCommand.h"

#include "NavigationSystem.h"
#include "Game/DesignPatterns/Behavioral/Command/MIAIController_Command.h"

void UMIMoveToCommand::Initialize(AMIAIController_Command* InReceiver, const FVector& InLocation)
{
	if (!IsValid(InReceiver))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Initialize failed - invalid Receiver"), *GetNameSafe(this));
		return;
	}

	if (!InLocation.IsNearlyZero()) // Basic location validation
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Initialize failed - invalid Location"), *GetNameSafe(this));
		return;
	}

	Receiver = InReceiver;
	TargetLocation = InLocation;
}

void UMIMoveToCommand::Execute_Implementation()
{
	if (!IsValid(Receiver))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Execute failed - invalid Receiver"), *GetNameSafe(this));
		return;
	}

	APawn* ControlledPawn = Receiver->GetPawn();
	if (!IsValid(ControlledPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Execute failed - no controlled pawn"), *GetNameSafe(this));
		return;
	}

	// Store current location for undo
	PrevLocation = ControlledPawn->GetActorLocation();

	// Validate navigation
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!IsValid(NavSystem))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Execute failed - navigation system unavailable"), *GetNameSafe(this));
		return;
	}

	// Check if location is reachable
	FNavLocation NavLocation;
	if (!NavSystem->ProjectPointToNavigation(TargetLocation, NavLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: Target location is not navigable"), *GetNameSafe(this));
		return;
	}

	// Execute move command
	Receiver->MoveToLocation(TargetLocation);
    
	UE_LOG(LogTemp, Log, TEXT("%s: Executed move to %s"), *GetNameSafe(this), *TargetLocation.ToString());
}

void UMIMoveToCommand::Undo_Implementation()
{
	if (!IsValid(Receiver) || !IsValid(Receiver->GetPawn()))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Undo failed - invalid Receiver or Pawn"), *GetNameSafe(this));
		return;
	}

	if (PrevLocation.IsNearlyZero())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: No valid previous location for undo"), *GetNameSafe(this));
		return;
	}

	// Move back to previous location
	Receiver->MoveToLocation(PrevLocation);
    
	UE_LOG(LogTemp, Log, TEXT("%s: Undo move - returning to %s"), *GetNameSafe(this), *PrevLocation.ToString());
}
