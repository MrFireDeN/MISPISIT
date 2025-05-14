// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Observer/MIAnimationTriggerComponent.h"

#include "Game/DesignPatterns/Behavioral/Observer/MITimeServerSubsystem.h"


UMIAnimationTriggerComponent::UMIAnimationTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMIAnimationTriggerComponent::OnTimeUpdate_Implementation(int32 NewTime)
{
	if (NewTime % AnimationTriggerTime == 0)
	{
		USkeletalMeshComponent* MeshComponent = Cast<USkeletalMeshComponent>(GetOwner()->FindComponentByClass(USkeletalMeshComponent::StaticClass()));

		if (MeshComponent && AnimMontage)
		{
			MeshComponent->GetAnimInstance()->Montage_Play(AnimMontage);
		}
		
		UE_LOG(LogTemp, Display, TEXT("[%s] Play Animation"), *GetNameSafe(this));
	}
}

void UMIAnimationTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Subscribe(this);
	}
}

void UMIAnimationTriggerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Unsubscribe(this);
	}
}
