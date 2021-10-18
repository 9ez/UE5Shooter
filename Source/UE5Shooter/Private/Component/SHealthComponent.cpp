// THEY. All Rights Reserved.

#include "Components/SHealthComponent.h"

#include "Dev/SFireDamageType.h"
#include "Dev/SIceDamageType.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

USHealthComponent::USHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;

    AActor* ComponentOwner = GetOwner();

    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USHealthComponent::OnTakeAnyDamage);
    }
}

void USHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    Health -= Damage;
    UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);

    if (DamageType)
    {
        if (DamageType->IsA<USFireDamageType>())
        {
            UE_LOG(LogHealthComponent, Display, TEXT("Hot"));
        }
        else if (DamageType->IsA<USIceDamageType>())
        {
            UE_LOG(LogHealthComponent, Display, TEXT("Cold"));
        }
    }
}