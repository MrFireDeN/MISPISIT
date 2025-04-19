// MIPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "../MICharacterBase.h"
#include "Game/Characters/Components/MICharacterMovementComponent.h"
#include "MIPlayerCharacter.generated.h"

class UMICharacterMovementComponent;

UCLASS()
class MISPISIT_API AMIPlayerCharacter : public AMICharacterBase
{
	GENERATED_BODY()

public:
	AMIPlayerCharacter();
	explicit AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE TObjectPtr<UMICharacterMovementComponent> GetMIMovement() const
	{
		return Cast<UMICharacterMovementComponent>(GetCharacterMovement());
	}
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
};
