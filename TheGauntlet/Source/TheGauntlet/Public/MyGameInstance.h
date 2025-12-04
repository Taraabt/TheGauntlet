#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"


UCLASS()
class THEGAUNTLET_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    void StartGame(FName InGameplayLevel);

    UFUNCTION(BlueprintCallable, Category = "Game")
    void ReturnToMenu(FName InMainMenuLevel);

private:

    FName MainMenuLevel;


    FName GameplayLevel;
};
