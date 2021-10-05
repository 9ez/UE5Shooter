// THEY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBaseCharacter.generated.h"

class UCameraComponent;

UCLASS()
class UE5SHOOTER_API ASBaseCharacter final : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ASBaseCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent *CameraComponent;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
};
