#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyPlayerController.h"

AMyCharacter::AMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (APlayerController* PC = Cast<APlayerController>(NewController))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            if (MappingContext)
            {
                Subsystem->AddMappingContext(MappingContext, 0);
            }
        }
    }
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (MoveAction)
            EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

        if (LookAction)
            EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);

        if (JumpAction)
        {
            EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AMyCharacter::DoJumpStart);
            EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::DoJumpEnd);
        }
    }
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();
    DoMove(MovementVector.X, MovementVector.Y);
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookVector = Value.Get<FVector2D>();
    DoLook(LookVector.X, LookVector.Y);
}

void AMyCharacter::DoMove(float Right, float Forward)
{
    if (Controller)
    {
        AddMovementInput(FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X), Forward);
        AddMovementInput(FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::Y), Right);
    }
}

void AMyCharacter::DoLook(float Yaw, float Pitch)
{
    AddControllerYawInput(Yaw);
    AddControllerPitchInput(Pitch);
}

void AMyCharacter::DoJumpStart()
{
    Jump();
}

void AMyCharacter::DoJumpEnd()
{
    StopJumping();
}
