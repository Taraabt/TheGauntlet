#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetMenuMode(); // esempio
}

void AMyPlayerController::SetMenuMode()
{
    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);

    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void AMyPlayerController::SetGameplayMode()
{
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);

    bShowMouseCursor = false;
    bEnableClickEvents = false;
    bEnableMouseOverEvents = false;
}
