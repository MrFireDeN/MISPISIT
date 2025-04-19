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
	AMIPlayerCharacter();
	explicit AMIPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
};
