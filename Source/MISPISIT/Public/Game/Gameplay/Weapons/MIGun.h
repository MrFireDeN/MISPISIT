// MIGun.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "MIGun.generated.h"

class UStaticMeshComponent;
class IMIGunState;

UENUM(BlueprintType)
enum EFireMode : uint8
{
	Single,
	Auto,
	Burst
};

UCLASS(Abstract, BlueprintType)
class MISPISIT_API AMIGun : public AActor, public ICPP_Interactable
{
	GENERATED_BODY()

public:
	AMIGun();

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual bool OnPrimaryAction() override;

	virtual void StartFire();
	virtual void StopFire();
	virtual void Reload();

	void SetState(TScriptInterface<IMIGunState> NewState);

	UFUNCTION(BlueprintPure, Category = "Gun")
	TScriptInterface<IMIGunState> GetCurrentState() const { return CurrentState; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	UStaticMeshComponent* Mesh;
	
	/** Character currently wielding this weapon */
	UPROPERTY(BlueprintReadOnly)
	ACharacter* CharacterOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	uint8 FireMode = EFireMode::Single;

private:
	UPROPERTY()
	TScriptInterface<IMIGunState> CurrentState;
};
