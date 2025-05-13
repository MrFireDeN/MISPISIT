// MIInteractableBase.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "MIInteractableBase.generated.h"

class AMICharacterBase;
class UStaticMeshComponent;
class UBoxComponent;
class UTraceHelper;

UCLASS(BlueprintType, Blueprintable)
class MISPISIT_API AMIInteractableBase : public AActor, public ICPP_Interactable
{
	GENERATED_BODY()

public:
	AMIInteractableBase();

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;

	UFUNCTION(BlueprintPure, Category = "Interactable")
	AMICharacterBase* GetCharacterOwner() const { return CharacterOwner; }

	UFUNCTION(BlueprintPure, Category = "Interactable")
	UTraceHelper* GetTraceHelper() { return TraceHelper; }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Interactable")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "Interactable")
	TObjectPtr<UBoxComponent> BoxCollision;

private:
	UPROPERTY()
	TObjectPtr<AMICharacterBase> CharacterOwner = nullptr;

	UPROPERTY()
	TObjectPtr<UTraceHelper> TraceHelper = nullptr;
};
