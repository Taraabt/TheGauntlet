#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);

UCLASS()
class THEGAUNTLET_API AMyGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AMyGameModeBase();


    UFUNCTION(BlueprintCallable)
    void LevelCompleted();

    UFUNCTION(BlueprintCallable)
    void PlayerDied();

    UPROPERTY(BlueprintAssignable)
    FOnLevelCompleted OnLevelCompleted;

    UPROPERTY(BlueprintAssignable)
    FOnPlayerDied OnPlayerDied;
};
