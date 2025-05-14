// UMILookAtCommand.cpp


#include "Game/DesignPatterns/Behavioral/Command/MILookAtCommand.h"

#include "Game/DesignPatterns/Behavioral/Command/MIAIController_Command.h"

void UMILookAtCommand::Initialize(AMIAIController_Command* InReceiver, AActor* InTarget)
{
	if (!IsValid(InReceiver))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Invalid Receiver provided"), *GetNameSafe(this));
		return;
	}

	if (!IsValid(InTarget))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Invalid Target provided"), *GetNameSafe(this));
		return;
	}

	Receiver = InReceiver;
	Target = InTarget;
}

void UMILookAtCommand::Execute_Implementation()
{
	if (!IsValid(Receiver) || !IsValid(Target))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: Cannot execute - invalid Receiver or Target"), *GetNameSafe(this));
		return;
	}

	APawn* ControlledPawn = Receiver->GetPawn();
	if (!IsValid(ControlledPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: No controlled pawn"), *GetNameSafe(this));
		return;
	}

	PrevRotation = ControlledPawn->GetActorRotation();
	
	const FVector DirectionToTarget = Target->GetActorLocation() - ControlledPawn->GetActorLocation();
	const FRotator NewRotation = DirectionToTarget.Rotation();
	const FRotator YawOnlyRotation(0.f, NewRotation.Yaw, 0.f);
    
	ControlledPawn->SetActorRotation(YawOnlyRotation);
    
	UE_LOG(LogTemp, Log, TEXT("%s: Executed look at %s"), *GetNameSafe(this), *GetNameSafe(Target));
}

void UMILookAtCommand::Undo_Implementation()
{
	if (IsValid(Receiver) && IsValid(Receiver->GetPawn()))
	{
		Receiver->GetPawn()->SetActorRotation(PrevRotation);
	}
    
	UE_LOG(LogTemp, Log, TEXT("%s: Undo rotation"), *GetNameSafe(this));
}
