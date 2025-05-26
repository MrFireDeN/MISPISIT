// MIGun.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "Flyweight/CPP_SpraySubsystem.h"
#include "MIGun.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class IMIGunState;
class UTraceHelper;
class UCPP_SpraySubsystem;
class UAudioComponent;
class USoundBase;

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

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintPure, Category = "Gun")
	TScriptInterface<IMIGunState> GetCurrentState() const { return CurrentState; }

	UFUNCTION(BlueprintPure, Category = "Gun")
	EFireMode GetFireMode() const { return FireMode; }

	UFUNCTION(BlueprintPure, Category = "Gun")
	float GetReloadDelay() const { return ReloadDelay; }

	UFUNCTION(BlueprintPure, Category = "Gun")
	float GetFireRate() const { return FireRate; }
	
	UFUNCTION(BlueprintPure, Category = "Gun")
	int32 GetBurstShotsCount() const { return BurstShotsCount; }

	UPROPERTY()
	int32 RemainingBurstShots = 0;
	
	/** Current shot counter for spray pattern sequencing */
	UPROPERTY()
	int32 ShotIndex = 0;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Gun")
	TObjectPtr<UAudioComponent> AudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	TObjectPtr<USoundBase> FireSound;
	
	/** Character currently wielding this weapon */
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACharacter> CharacterOwner;

	/** Subsystem managing shared spray patterns (Flyweight pattern) */
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	TObjectPtr<UCPP_SpraySubsystem> SpraySubsystem;

	/** Type of weapon spray pattern to use */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	ESprayType SprayType;

	/** Base damage per shot */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float Damage = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	EFireMode FireMode = EFireMode::Single;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float ReloadDelay = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float FireRate = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	int32 BurstShotsCount = 3;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTraceHelper> TraceHelper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float RecoilDuration = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Gun")
	float RecoilStrength = 10.f;

private:
	UPROPERTY()
	TScriptInterface<IMIGunState> CurrentState;

	void ApplyRecoil();
	FTimerHandle RecoilApplyTimer;
	FTimerHandle RecoilDurationTimer;
};
