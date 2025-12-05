#include "Door.h"
#include "Components/StaticMeshComponent.h"

ADoor::ADoor()
{
    PrimaryActorTick.bCanEverTick = true;

    DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    RootComponent = DoorMesh;
}

void ADoor::BeginPlay()
{
    Super::BeginPlay();

    ClosedRotation = DoorMesh->GetRelativeRotation();
}

void ADoor::Interact_Implementation(ACharacter* InteractingCharacter)
{
    bIsOpen = !bIsOpen;

    FRotator TargetRotation;

    if (bIsOpen)
    {
       
        TargetRotation = ClosedRotation + FRotator(0.f, 90.f, 0.f);
    }
    else
    {
        TargetRotation = ClosedRotation;
    }
    DoorMesh->SetRelativeRotation(TargetRotation);

}
