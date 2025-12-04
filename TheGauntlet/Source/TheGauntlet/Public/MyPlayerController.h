#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UCLASS()
class THEGAUNTLET_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetMenuMode();

    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetGameplayMode();

    UFUNCTION(BlueprintCallable, Category = "Input")
    void OnLevelLoaded();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputMappingContext* DefaultMappingContext;

private:
    void AutoPossessPawn();
};
