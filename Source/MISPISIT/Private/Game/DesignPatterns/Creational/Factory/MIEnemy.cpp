// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Creational/Factory/MIEnemy.h"

#include "Components/CapsuleComponent.h"
#include "Game/Gameplay/MIShootingRangeSubsystem.h"


AMIEnemy::AMIEnemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Создаем компонент скелетного меша
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -90.0f, 0.0f));
    
	// Загружаем скелетный меш из контента
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}
    
	// Загружаем анимационный блюпринт
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimAsset(TEXT("/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny"));
	if (AnimAsset.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAsset.Object->GeneratedClass);
	}

	// Включаем коллизию для капсулы (если это Character)
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block); // Блокирует все каналы
    
	// Настраиваем коллизию для меша
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetCollisionObjectType(ECC_Pawn); // Или ECC_WorldDynamic
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block); // Блокирует трассировку видимости
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);   // Игнорирует камеру (опционально)
}

void AMIEnemy::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
	{
		Destroy();
	}, 5, false);
}

void AMIEnemy::HandleDeath_Implementation()
{
	Super::HandleDeath_Implementation();

	GetWorld()->GetSubsystem<UMIShootingRangeSubsystem>()->AddScore();
}
