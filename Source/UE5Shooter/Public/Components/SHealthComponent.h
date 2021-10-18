// THEY. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SHealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE5SHOOTER_API USHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USHealthComponent();

    float GetHealth() const { return Health; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (ClampMin =  "0", ClampMax = "1000.0"))
    float MaxHealth = 100;

    virtual void BeginPlay() override;

    UFUNCTION()
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

private:
    float Health = 0;
};
