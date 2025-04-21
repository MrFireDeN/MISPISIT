// MICharacterInteractComponent.cpp

#include "Game/Characters/Components/MICharacterInteractComponent.h"
#include "InteractableHelper.h"

UMICharacterInteractComponent::UMICharacterInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMICharacterInteractComponent::StartHover(TScriptInterface<ICPP_Interactable> Target)
{
	if (!Target) return;

	if (AActor* InteractableActor = Cast<AActor>(Target.GetObject()))
	{
		Interactable = Target;
		UInteractableHelper::CallOnTouch(InteractableActor);
	}
}

void UMICharacterInteractComponent::EndHover(TScriptInterface<ICPP_Interactable> Target)
{
	if (!Target) return;

	if (Target == Interactable)
	{
		if (AActor* InteractableActor = Cast<AActor>(Target.GetObject()))
		{
			UInteractableHelper::CallOnUnTouch(InteractableActor);
		}

		Interactable = nullptr;
	}
}

void UMICharacterInteractComponent::AttachInteractable(USkeletalMeshComponent* TargetMesh, FName BoneName)
{
	if (!TargetMesh || !Interactable) return;

	// Detach existing actor before attaching new one
	if (AttachedActor)
	{
		// Check if the interactable actor is the same as the currently attached one
		const bool bIsSameInteractable = Interactable == AttachedActor;
		
		DetachInteractable();
		
		if (bIsSameInteractable) return;
	}

	AttachedActor = Cast<AActor>(Interactable.GetObject());

	if (AttachedActor)
	{
		const FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
		AttachedActor->AttachToComponent(TargetMesh, TransformRules, BoneName);
		UInteractableHelper::CallOnAttach(AttachedActor);
	}
}

void UMICharacterInteractComponent::DetachInteractable()
{
	if (!AttachedActor) return;

	const FDetachmentTransformRules TransformRules(EDetachmentRule::KeepWorld, true);
	AttachedActor->DetachFromActor(TransformRules);
	UInteractableHelper::CallOnDetach(AttachedActor);

	AttachedActor = nullptr;
}