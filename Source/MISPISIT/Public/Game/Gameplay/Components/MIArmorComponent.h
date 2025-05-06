// MIArmorComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Game/DesignPatterns/Behavioral/Strategy/MIDamageStrategyProvider.h"
#include "MIArmorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnArmorsChangedSignature, TArray<UMIArmor*> const&, Armors);

class UMIArmor;
class IMIDamageStrategy;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIArmorComponent : public UActorComponent, public IMIDamageStrategyProvider
{
	GENERATED_BODY()

public:
	UMIArmorComponent();
	
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnArmorsChangedSignature OnArmorsChanged;

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual float TakeDamage(const float Damage);

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual void AddArmor(UMIArmor* NewArmor);

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual void RemoveArmor(UMIArmor* NewArmor);

	virtual TArray<TScriptInterface<IMIDamageStrategy>> GetDamageStrategies_Implementation() const override;

private:
	TArray<TObjectPtr<UMIArmor>> Armors;
};
