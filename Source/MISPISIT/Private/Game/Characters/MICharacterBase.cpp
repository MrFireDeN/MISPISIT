// MICharacterBase.cpp

#include "Game/Characters/MICharacterBase.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "Game/Characters/Components/MICharacterInteractComponent.h"
#include "Game/Gameplay/Components/MIHealthComponent.h"

AMICharacterBase::AMICharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMICharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Create and attach the interaction component responsible for object interaction logic
	InteractComponent = CreateDefaultSubobject<UMICharacterInteractComponent>(TEXT("InteractComponent"));
	HealthComponent = CreateDefaultSubobject<UMIHealthComponent>(TEXT("HealthComponent"));
}

UMICharacterMovementComponent* AMICharacterBase::GetCharacterMovement() const
{
	// Returns the custom character movement component used for advanced locomotion features
	return Cast<UMICharacterMovementComponent>(Super::GetCharacterMovement());
}

UMICharacterInteractComponent* AMICharacterBase::GetInteractComponent() const
{
	// Provides access to the interaction component that handles hover/attach behavior
	return InteractComponent;
}

UMIHealthComponent* AMICharacterBase::GetHealthComponent() const
{
	return HealthComponent;
}

void AMICharacterBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// Start hover interaction if the overlapping actor implements the interactable interface
	if (OtherActor && OtherActor->GetClass()->ImplementsInterface(UCPP_Interactable::StaticClass()))
	{
		GetInteractComponent()->StartHover(TScriptInterface<ICPP_Interactable>(OtherActor));
	}
}

void AMICharacterBase::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	// End hover interaction if the actor matches the current interactable
	if (OtherActor && OtherActor->GetClass()->ImplementsInterface(UCPP_Interactable::StaticClass()))
	{
		GetInteractComponent()->EndHover(TScriptInterface<ICPP_Interactable>(OtherActor));
	}
}

void AMICharacterBase::InteractByHand()
{
	// Attaches the interactable to the character's right hand bone
	GetInteractComponent()->AttachInteractable(GetMesh(), RightHandName);
}

float AMICharacterBase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	if (HealthComponent->IsDead()) return 0;
	
	const float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	
	HealthComponent->TakeDamage(Damage);
	
	return Damage;
}
