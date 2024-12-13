// CPP_SniperRifleBuilder.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_WeaponBuilder.h"
#include "CPP_SniperRifle.h"
#include "AssetLoader.h"
#include "Components/SpotLightComponent.h"
#include "CPP_SniperRifleBuilder.generated.h"

UCLASS(BlueprintType)
class MISPISIT_API ACPP_SniperRifleBuilder : public AActor, public ICPP_WeaponBuilder
{
	GENERATED_BODY()

public:
	ACPP_SniperRifleBuilder();

protected:
	virtual void BeginPlay() override;

	FWeaponData WeaponData;
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetBarrel(const FString& Color); virtual bool SetBarrel_Implementation(const FString& Color) override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetChamber(); virtual bool SetChamber_Implementation() override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetMagazine(const FString& Size); virtual bool SetMagazine_Implementation(const FString& Size) override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetTrigger(); virtual bool SetTrigger_Implementation() override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetScope(const FString& Name); virtual bool SetScope_Implementation(const FString& Name) override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool SetAddition(const FString& Name); virtual bool SetAddition_Implementation(const FString& Name) override;
  
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "WeaponBuilder")
	bool ResetState(); virtual bool ResetState_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "WeaponBuilder")
	ACPP_SniperRifle* GetResult();
};