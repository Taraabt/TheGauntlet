#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMyGameInstance::StartGame(FName InGameplayLevel)
{
    if (!InGameplayLevel.IsNone())
    {
        GameplayLevel = InGameplayLevel;
        UGameplayStatics::OpenLevel(this, GameplayLevel);
    }
}

void UMyGameInstance::ReturnToMenu(FName InMainMenuLevel)
{
    if (!InMainMenuLevel.IsNone())
    {
        MainMenuLevel = InMainMenuLevel;
        UGameplayStatics::OpenLevel(this, MainMenuLevel);
    }
}
