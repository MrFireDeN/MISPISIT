// CPP_ProductBox.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_Interactable.h"
#include "CPP_IProduct.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "CPP_ProductBox.generated.h"

UCLASS()
class MISPISIT_API ACPP_ProductBox : public AActor, public ICPP_Interactable, public ICPP_IProduct
{
	GENERATED_BODY()

public:
	ACPP_ProductBox();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BoxMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

public:
	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
};
