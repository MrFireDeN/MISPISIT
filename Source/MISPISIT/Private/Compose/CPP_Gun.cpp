// Fill out your copyright notice in the Description page of Project Settings.


#include "Compose/CPP_Gun.h"

ACPP_Gun::ACPP_Gun()
{
	ProductMesh->SetRelativeScale3D(FVector(0.5));
	
	UAssetLoader::LoadMeshFromAsset(ProductMesh, "/Game/Project/Models/Weapons/Colored_Guns_OTs-14_Groza.Colored_Guns_OTs-14_Groza");
	
	Name = "OTs-14 Groza";
	Price = 1500;
}

void ACPP_Gun::BeginPlay()
{
	TraceHelper = GetWorld()->GetSubsystem<UTraceHelper>();
	
	if (TraceHelper == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
			TEXT("Failed to load TraceHelper"));
	}
}

void ACPP_Gun::Fire(FHitResult Hit)
{
	if (!Hit.IsValidBlockingHit())
	{
		return;
	}
	
	AActor* HitActor = Hit.GetActor();

	if (HitActor == nullptr)
	{
		return;
	}

	const FPointDamageEvent DamageEvent(Damage, Hit, GetActorForwardVector(), nullptr);
	HitActor->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);

	if (CharacterOwner != nullptr)
	{
		CharacterOwner->AddControllerPitchInput(-2);
	}
}

bool ACPP_Gun::OnAttach()
{
	CharacterOwner = Cast<ACharacter>(GetAttachParentActor());
    
	// Проверка успешности
	if (!CharacterOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun attached to non-character owner!"));
	}
	
	return Super::OnAttach();
}

bool ACPP_Gun::OnDetach()
{
	CharacterOwner = nullptr;
		
	return Super::OnDetach();
}

bool ACPP_Gun::OnPrimaryAction()
{
	
	if (TOptional<FHitResult> HitResult = TraceHelper->TraceFromPlayer(5000, true))
	{
		const FHitResult Hit = *HitResult;
		
		if (Hit.GetActor()->StaticClass() == ACPP_ProductBox::StaticClass())
		{
			return Super::OnPrimaryAction();
		}
		
		Fire(Hit);
	}
	
	return true;
}
