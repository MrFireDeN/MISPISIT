// CPP_Scanner.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "Components/BoxComponent.h"
#include "CPP_Scanner.generated.h"

UCLASS()
class MISPISIT_API ACPP_Scanner : public AActor, public ICPP_Interactable
{
	GENERATED_BODY()

public:
	ACPP_Scanner();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ScannerMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

public:
};
