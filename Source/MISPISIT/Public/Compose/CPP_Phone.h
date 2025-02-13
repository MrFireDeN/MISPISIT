// CPP_Phone.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "CPP_IProduct.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AssetLoader.h"
#include "CPP_ProductBox.h"
#include "InteractableHelper.h"
#include "CPP_Phone.generated.h"

UCLASS()
class MISPISIT_API ACPP_Phone : public AActor, public ICPP_Interactable, public ICPP_IProduct
{
	GENERATED_BODY()

public:
	ACPP_Phone();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* PhoneMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

	APlayerCameraManager* CameraManager;
	
	FName Name = "Google Pixel 7a";
	float Price = 1000;
	
public:
	virtual float GetPrice() override;
	virtual FName GetName() override;
	virtual void PlaceInBox(AActor* Box) override;
	virtual void PlaceInWorld() override;

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual bool OnPrimaryAction() override;
};
