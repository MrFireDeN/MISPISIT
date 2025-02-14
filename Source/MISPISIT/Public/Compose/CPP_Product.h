// CPP_Product.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "CPP_IProduct.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AssetLoader.h"
#include "CPP_ProductBox.h"
#include "InteractableHelper.h"
#include "CPP_Product.generated.h"

UCLASS()
class MISPISIT_API ACPP_Product : public AActor, public ICPP_Interactable, public ICPP_IProduct
{
	GENERATED_BODY()

public:
	ACPP_Product();

protected:
	UPROPERTY(EditAnywhere, Category = "Product")
	UStaticMeshComponent* ProductMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

	APlayerCameraManager* CameraManager;
	
	UPROPERTY(EditAnywhere, Category = "Product")
	FName Name = "Product";
	
	UPROPERTY(EditAnywhere, Category = "Product")
	float Price = 10;
	
public:
	virtual float GetPrice() override;
	virtual FName GetName() override;
	virtual void PlaceInBox(AActor* Box) override;
	virtual void PlaceInWorld() override;

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual bool OnPrimaryAction() override;
};
