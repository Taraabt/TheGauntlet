#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Door.generated.h"

UCLASS()
class THEGAUNTLET_API ADoor : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    ADoor();


protected:
    virtual void BeginPlay() override;

public:

    virtual void Interact_Implementation(ACharacter* InteractingCharacter) override;

    void OnInteracted(ACharacter* InteractingCharacter);

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* DoorMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsOpen = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRotator OpenRotation;

private:
    FRotator ClosedRotation;
};
