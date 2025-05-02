// MIArmorComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MIArmorComponent.generated.h"

class UMIArmor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MISPISIT_API UMIArmorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMIArmorComponent();

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual float TakeDamage(const float Damage);

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual void AddArmor(UMIArmor* NewArmor);

	UFUNCTION(BlueprintCallable, Category="Armor")
	virtual void RemoveArmor(UMIArmor* NewArmor);

private:
	TArray<TObjectPtr<UMIArmor>> Armors;
};
