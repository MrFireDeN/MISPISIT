// CPP_Scanner.h

#pragma once

#include "CoreMinimal.h"
#include "CPP_Interactable.h"
#include "GameFramework/Actor.h"
#include "AssetLoader.h"
#include "CPP_IProduct.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Compose/CPP_ProductBox.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
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

	APlayerCameraManager* CameraManager;

	virtual void BeginPlay() override;

	virtual void ScanProduct(ICPP_IProduct* Product);
public:
	virtual bool OnPrimaryAction() override;
	virtual bool OnSecondaryAction() override;

	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
};
