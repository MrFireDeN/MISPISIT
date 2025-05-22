// MIPuzzlePlate.h

#pragma once

#include "CoreMinimal.h"
#include "MIPuzzleElementBase.h"
#include "MIPuzzlePlate.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class MISPISIT_API AMIPuzzlePlate : public AMIPuzzleElementBase
{
	GENERATED_BODY()

public:
	AMIPuzzlePlate();

	UFUNCTION(BlueprintPure, Category = "Plate")
	bool IsPressured() const { return bIsPressured; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plate", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> TriggerZone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plate", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	bool bIsPressured = false;

	UFUNCTION(BlueprintImplementableEvent, Category = "Plate")
	void OnPressured();

	UFUNCTION(BlueprintImplementableEvent, Category = "Plate")
	void OnUnpressured();
};
