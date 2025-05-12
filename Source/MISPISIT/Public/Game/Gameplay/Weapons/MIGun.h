// MIGun.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "MIGun.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class IMIGunState;

UENUM(BlueprintType)
enum class EFireMode : uint8
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
	virtual bool OnPrimaryAction_Stopped() override;

	virtual void StartFire();
	virtual void StopFire();
	virtual void Reload();

	void SetState(TScriptInterface<IMIGunState> NewState);

	UFUNCTION(BlueprintPure, Category = "Gun")
	TScriptInterface<IMIGunState> GetCurrentState() const { return CurrentState; }

	UFUNCTION(BlueprintPure, Category = "Gun")
	EFireMode GetFireMode() const { return FireMode; }

	UFUNCTION(BlueprintPure, Category = "Gun")
	float GetReloadDelay() const { return ReloadDelay; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	UBoxComponent* BoxCollision;
	
	/** Character currently wielding this weapon */
	UPROPERTY(BlueprintReadOnly)
	ACharacter* CharacterOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	EFireMode FireMode = EFireMode::Single;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float ReloadDelay = 2.f;

private:
	UPROPERTY()
	TScriptInterface<IMIGunState> CurrentState;
};
