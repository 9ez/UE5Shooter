// THEY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USHealthComponent;
class UTextRenderComponent;

UCLASS()
class UE5SHOOTER_API ASBaseCharacter final : public ACharacter
{
    GENERATED_BODY()

public:
    ASBaseCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent* HealthTextComponent;

public:
    virtual void Tick(const float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin =  "0", ClampMax = "1200.0"))
    float Walk_Speed = 600;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0", ClampMax = "2400.0"))
    float Run_Speed = 1200;
    
private:
    bool WantsToRun = false;
    void MoveForward(const float Amount);
    void MoveRight(const float Amount) { AddMovementInput(GetActorRightVector(), Amount); }
    void Run() { WantsToRun = true; }
    void EndRun() { WantsToRun = false; }
};
