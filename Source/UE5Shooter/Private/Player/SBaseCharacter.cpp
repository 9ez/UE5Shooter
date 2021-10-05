// THEY. All Rights Reserved.

#include "Player/SBaseCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASBaseCharacter::ASBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASBaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASBaseCharacter::MoveRight);
}

void ASBaseCharacter::MoveForward(float const Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASBaseCharacter::MoveRight(float const Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}
