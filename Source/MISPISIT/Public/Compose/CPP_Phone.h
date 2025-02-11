// CPP_Phone.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "CPP_IProduct.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AssetLoader.h"
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
	
	FName Name = "Google Pixel 7a";
	float Price = 1000;
	
public:
	virtual float GetPrice() override;
	virtual FName GetName() override;
	virtual void PlaceInBox() override;

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
};
