#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    // Imposta la classe di default per il Pawn
    DefaultPawnClass = AMyCharacter::StaticClass();

    // Imposta la classe di default per il PlayerController
    PlayerControllerClass = AMyPlayerController::StaticClass();
}

void AMyGameModeBase::LevelCompleted()
{
    OnLevelCompleted.Broadcast();
}

void AMyGameModeBase::PlayerDied()
{
    OnPlayerDied.Broadcast();
}
