// MIGameMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MIGameMode.generated.h"

class AMIPlayerCharacter;
class AMIPlayerHUD;
class AMIPlayerController;
class AMIGameState;
class AMIPlayerState;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, config = Game)
class MISPISIT_API AMIGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMIGameMode();

public:
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void RespawnPlayer(AController* PlayerController) const;
};
