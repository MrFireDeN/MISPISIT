// MIPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "../MICharacterBase.h"
#include "MIPlayerCharacter.generated.h"

UCLASS()
class MISPISIT_API AMIPlayerCharacter : public AMICharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMIPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
