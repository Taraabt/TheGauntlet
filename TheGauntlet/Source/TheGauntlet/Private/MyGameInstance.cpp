#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMyGameInstance::StartGame(FName GameplayLevel)
{
    UGameplayStatics::OpenLevel(this, GameplayLevel);
}

void UMyGameInstance::ReturnToMenu(FName MainMenuLevel)
{
    UGameplayStatics::OpenLevel(this, MainMenuLevel);
}

void UMyGameInstance::QuitGame()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}
