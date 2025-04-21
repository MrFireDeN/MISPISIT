// MIGameMode.cpp

#include "Game/Core/MIGameMode.h"
#include "Game/Characters/Player/MIPlayerCharacter.h"
#include "Game/Characters/Player/MIPlayerHUD.h"
#include "Game/Characters/Player/MIPlayerController.h"
#include "Game/Core/MIGameState.h"
#include "Game/Characters/Player/MIPlayerState.h"

AMIGameMode::AMIGameMode()
{
	PlayerControllerClass = AMIPlayerController::StaticClass();
	DefaultPawnClass = AMIPlayerCharacter::StaticClass();
	HUDClass = AMIPlayerHUD::StaticClass();
	GameStateClass = AMIGameState::StaticClass();
	PlayerStateClass = AMIPlayerState::StaticClass();
}

void AMIGameMode::RespawnPlayer(AController* PlayerController) const
{
	if (!PlayerController || !DefaultPawnClass) return;

	// Уничтожаем текущего персонажа игрока
	if (APawn* OldPawn = PlayerController->GetPawn())
	{
		OldPawn->Destroy();
	}

	// Спавним нового персонажа
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    
	if (APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams))
	{
		PlayerController->Possess(NewPawn);
	}
}
