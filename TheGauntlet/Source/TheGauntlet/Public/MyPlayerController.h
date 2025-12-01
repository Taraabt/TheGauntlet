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

    void SetMenuMode();     // Mouse visibile, no input movimento
    void SetGameplayMode(); // Mouse nascosto, input movimento attivo
};
