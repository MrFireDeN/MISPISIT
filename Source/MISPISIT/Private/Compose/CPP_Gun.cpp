#include "Compose/CPP_Gun.h"

/**
 * Initializes gun properties and loads 3D model.
 * Sets default scale and weapon parameters.
 */
ACPP_Gun::ACPP_Gun()
{
    ProductMesh->SetRelativeScale3D(FVector(0.5));
    
    UAssetLoader::LoadMeshFromAsset(ProductMesh, 
        "/Game/Project/Models/Weapons/Colored_Guns_OTs-14_Groza.Colored_Guns_OTs-14_Groza");
    
    Name = "OTs-14 Groza";
    Price = 1500;
}

/**
 * Initializes required subsystems and validates dependencies.
 * Called when actor is spawned into the world.
 */
void ACPP_Gun::BeginPlay()
{
    Super::BeginPlay();

    // Initialize trace helper subsystem
    TraceHelper = GetWorld()->GetSubsystem<UTraceHelper>();
    if (!TraceHelper)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
            TEXT("Failed to load TraceHelper subsystem"));
    }

    // Initialize spray pattern subsystem
    SpraySubsystem = GetWorld()->GetSubsystem<UCPP_SpraySubsystem>();
    if (!SpraySubsystem)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
            TEXT("Failed to load SpraySubsystem"));
    }
}

/**
 * Handles weapon firing logic including:
 * - Applying damage to hit actor
 * - Processing recoil using spray pattern
 * @param Hit - Valid hit result from weapon trace
 */
void ACPP_Gun::Fire(FHitResult Hit)
{
    if (!Hit.IsValidBlockingHit())
    {
        return;
    }
    
    AActor* HitActor = Hit.GetActor();
    if (!HitActor)
    {
        return;
    }

    // Apply damage with proper damage event
    const FPointDamageEvent DamageEvent(Damage, Hit, GetActorForwardVector(), nullptr);
    HitActor->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);

    // Apply recoil if valid owner exists
    if (CharacterOwner && SpraySubsystem)
    {
        const FCPP_SprayPattern* SprayPattern = SpraySubsystem->GetSprayPattern(SprayType);
        if (SprayPattern)
        {
            const FVector2D Recoil = SprayPattern->GetSprayOffset(ShotIndex);
            CharacterOwner->AddControllerPitchInput(-Recoil.X);
            CharacterOwner->AddControllerYawInput(Recoil.Y);
            ShotIndex++;
        }
    }
}

/**
 * Handles weapon attachment to character
 * @return True if attachment succeeded
 */
bool ACPP_Gun::OnAttach()
{
    ShotIndex = 0; // Reset shot counter
    
    CharacterOwner = Cast<ACharacter>(GetAttachParentActor());
    if (!CharacterOwner)
    {
        UE_LOG(LogTemp, Warning, TEXT("Gun attached to non-character actor"));
    }
    
    return Super::OnAttach();
}

/**
 * Handles weapon detachment from character
 * @return True if detachment succeeded
 */
bool ACPP_Gun::OnDetach()
{
    CharacterOwner = nullptr;
    return Super::OnDetach();
}

/**
 * Primary fire action handler
 * @return True if action was processed
 */
bool ACPP_Gun::OnPrimaryAction()
{
    if (TOptional<FHitResult> HitResult = TraceHelper->TraceFromPlayer(5000, true))
    {
        const FHitResult& Hit = *HitResult;
        
        // Special case for product boxes
        if (Hit.GetActor()->IsA(ACPP_ProductBox::StaticClass()))
        {
            return Super::OnPrimaryAction();
        }
        
        Fire(Hit);
    }
    return true;
}