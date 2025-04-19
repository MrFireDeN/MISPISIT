// MICharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "MICharacterBase.generated.h"

class UMICharacterMovementComponent;

UCLASS(Abstract, BlueprintType, config = Game)
class MISPISIT_API AMICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMICharacterBase();
	explicit AMICharacterBase(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE UMICharacterMovementComponent* GetCharacterMovement() const
	{
		return Cast<UMICharacterMovementComponent>(Super::GetCharacterMovement());
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
