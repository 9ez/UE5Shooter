// THEY. All Rights Reserved.

#include "Components/SHealthComponent.h"

USHealthComponent::USHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
}
