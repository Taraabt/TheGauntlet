#include "MyGameModeBase.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{

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
