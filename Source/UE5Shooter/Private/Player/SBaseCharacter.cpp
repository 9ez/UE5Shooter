// THEY. All Rights Reserved.

#include "Player/SBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASBaseCharacter::ASBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called to bind functionality to input
void ASBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ASBaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASBaseCharacter::Run);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ASBaseCharacter::EndRun);
}

float ASBaseCharacter::GetMovementDirection() const
{
    const FVector Velocity = GetVelocity();
    if (Velocity.IsZero()) return 0.0f;
    const FVector ForwardVector = GetActorForwardVector();
    const FVector VelocityNormal = Velocity.GetSafeNormal();
    const FVector CrossProduct = FVector::CrossProduct(ForwardVector, VelocityNormal);
    return FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(ForwardVector, VelocityNormal))) *
        (CrossProduct.IsZero() ? 1 : FMath::Sign(CrossProduct.Z));
}

void ASBaseCharacter::MoveForward(const float Amount)
{
    GetCharacterMovement()->MaxWalkSpeed = WantsToRun && Amount > 0 ? RUN_SPEED : WALK_SPEED;
    AddMovementInput(GetActorForwardVector(), Amount);
}