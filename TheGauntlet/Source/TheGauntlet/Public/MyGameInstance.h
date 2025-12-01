#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"
#include <string>


UCLASS()
class THEGAUNTLET_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Game")
    void StartGame(FName GamePlayLevel);

    UFUNCTION(BlueprintCallable)
    void ReturnToMenu(FName MainMenuLevel);

    UFUNCTION(BlueprintCallable)
    void QuitGame();

protected:
    UPROPERTY(EditDefaultsOnly)
    FName MainMenuLevel;

    UPROPERTY(EditDefaultsOnly)
    FName GameplayLevel;
};
