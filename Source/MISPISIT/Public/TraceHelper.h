// TraceHelper.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TraceHelper.generated.h"

/**
 * Utility class for performing trace operations from player's or other perspective.
 * Handles camera management and world collision checks.
 */
UCLASS()
class MISPISIT_API UTraceHelper : public UObject
{
    GENERATED_BODY()

private:
    /** Cached reference to PlayerCameraManager. Marked Transient as it shouldn't be serialized. */
    UPROPERTY(Transient)
    APlayerCameraManager* CameraManager;

public:
    /**
     * Performs a forward line trace from the player's camera perspective.
     * 
     * @param Distance Maximum trace distance in world units (default: 1000.0f)
     * @param bDebug When true, draws debug sphere at hit location (red if hit, green if no hit)
     * 
     * @return TOptional<FHitResult> containing:
     *         - Hit data if trace was successful
     *         - Empty optional if:
     *           * World context is invalid
     *           * Player camera is unavailable
     *           * Trace didn't hit anything
     * 
     * @note Uses ECC_Visibility collision channel
     * @note Includes complex collisions and physical materials
     * @warning Debug drawing only appears in development builds
     * @see DrawDebugSphere(), ECC_Visibility, FCollisionQueryParams
     */
    TOptional<FHitResult> TraceFromPlayer(float Distance = 1000.0f, bool bDebug = false)
    {
        // Early return if world context is invalid
        if (!GetWorld())
        {
            UE_LOG(LogTemp, Error, TEXT("World is null"));
            return {};
        }
        
        // Lazy initialization of camera manager
        if (!CameraManager)
        {
            auto* PC = GetWorld()->GetFirstPlayerController();
            CameraManager = PC ? PC->PlayerCameraManager : nullptr;
        }

        if (!CameraManager)
        {
            UE_LOG(LogTemp, Error, TEXT("CameraManager is null"));
            return {};
        }

        // Calculate trace parameters
        const FVector StartLocation = CameraManager->GetCameraLocation();
        const FVector ForwardVector = CameraManager->GetActorForwardVector();
        const FVector EndLocation = StartLocation + (ForwardVector * Distance);
    
        FCollisionQueryParams TraceParams(FName(TEXT("LineTrace")), true);
        TraceParams.bTraceComplex = true;
        TraceParams.bReturnPhysicalMaterial = true;

        FHitResult HitResult;
        const bool bHit = GetWorld()->LineTraceSingleByChannel(
            HitResult,
            StartLocation,
            EndLocation,
            ECC_Visibility,
            TraceParams
        );

        if (!bHit)
        {
            UE_LOG(LogTemp, Warning, TEXT("Line trace didn't hit anything"));
            return {};
        }

        if (bDebug)
        {
            DrawDebugSphere(GetWorld(), HitResult.Location, 10.0f, 12, FColor::Green, false, 5.0f);
        }
        
        return HitResult;
    }
};