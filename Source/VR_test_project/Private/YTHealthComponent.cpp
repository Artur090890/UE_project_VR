// Fill out your copyright notice in the Description page of Project Settings.


#include "YTHealthComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UYTHealthComponent::UYTHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	DefaultHealth = 231;
	Health = DefaultHealth;
}

// Called when the game starts
void UYTHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	if (Owner) {
		Owner->OnTakeAnyDamage.AddDynamic(this, &UYTHealthComponent::TakeDamage);
	}
	
}

void UYTHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0) {
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
}

void UYTHealthComponent::DmgCharacter(float dmg)
{
	UYTHealthComponent::Health = UYTHealthComponent::Health - dmg;
	if (UYTHealthComponent::Health < 0) {
		UGameplayStatics::OpenLevel(this, "VRTemplateMap");
	}
}




