// MICharacterBase.cpp

#include "Game/Characters/MICharacterBase.h"

#include "Components/CapsuleComponent.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "Game/Characters/Components/MICharacterInteractComponent.h"
#include "Game/DesignPatterns/Behavioral/CoR/MIHealthDamageHandler.h"
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

void AMICharacterBase::HandleDeath_Implementation()
{
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetSimulatePhysics(true);
}

void AMICharacterBase::InitializeDamageChain_Implementation()
{
	auto* HealthHandler = NewObject<UMIHealthDamageHandler>(this);
	HealthHandler->SetHealthComponent(GetHealthComponent());
	
	DamageHandlerChain = HealthHandler;
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
	if (!ensure(HealthComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] TakeDamage: HealthComponent is NOT valid!"), *GetNameSafe(this));
		return 0.f;
	}

	if (DamageHandlerChain == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] TakeDamage: DamageHandlerChain is nullptr!"), *GetNameSafe(this));
		return 0.f;
	}
	
	if (GetHealthComponent()->IsDead()) return 0.f;

	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	ActualDamage = DamageHandlerChain->HandleDamage(ActualDamage, DamageEvent);

	if (GetHealthComponent()->IsDead())
	{
		HandleDeath();
	}

	if (ActualDamage > 0.f)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Took %.2f damage (after modifiers)"), *GetNameSafe(this), ActualDamage);
	}
	
	return ActualDamage;
}

void AMICharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	InitializeDamageChain_Implementation();
}
