#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

// Delegati
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);

UCLASS()
class THEGAUNTLET_API AMyGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AMyGameModeBase();

    // Funzioni chiamabili dal gioco
    UFUNCTION(BlueprintCallable)
    void LevelCompleted();

    UFUNCTION(BlueprintCallable)
    void PlayerDied();

    // Delegati
    UPROPERTY(BlueprintAssignable)
    FOnLevelCompleted OnLevelCompleted;

    UPROPERTY(BlueprintAssignable)
    FOnPlayerDied OnPlayerDied;
};
