#include "MyPlayerController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/GameModeBase.h"

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }

    SetMenuMode();
    AutoPossessPawn();
}

void AMyPlayerController::AutoPossessPawn()
{
    if (GetPawn())
        return;

    if (UWorld* World = GetWorld())
    {
        if (AGameModeBase* GM = World->GetAuthGameMode())
        {
            TSubclassOf<APawn> DefaultPawnClass = GM->GetDefaultPawnClassForController(this);

            if (DefaultPawnClass)
            {
                FActorSpawnParameters SpawnParams;
                SpawnParams.Owner = this;

                FVector LocalSpawnLocation = FVector::ZeroVector;
                FRotator LocalSpawnRotation = FRotator::ZeroRotator;

                APawn* SpawnedPawn = World->SpawnActor<APawn>(DefaultPawnClass, LocalSpawnLocation, LocalSpawnRotation, SpawnParams);


                if (SpawnedPawn)
                {
                    Possess(SpawnedPawn);
                    return;
                }
            }
        }
    }

    TArray<AActor*> FoundCharacters;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacter::StaticClass(), FoundCharacters);

    if (FoundCharacters.Num() > 0)
    {
        if (ACharacter* FirstCharacter = Cast<ACharacter>(FoundCharacters[0]))
        {
            Possess(FirstCharacter);
        }
    }
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

void AMyPlayerController::OnLevelLoaded()
{
    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }

    AutoPossessPawn();
    SetGameplayMode();
}
