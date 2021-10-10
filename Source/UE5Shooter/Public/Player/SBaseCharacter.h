// THEY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UE5SHOOTER_API ASBaseCharacter final : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ASBaseCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

private:
    const float WALK_SPEED = 600;
    const float RUN_SPEED = 1200;
    bool WantsToRun = false;
    void MoveForward(const float Amount);
    void MoveRight(const float Amount) { AddMovementInput(GetActorRightVector(), Amount); }
    void Run() { WantsToRun = true; }
    void EndRun() { WantsToRun = false; }
};
