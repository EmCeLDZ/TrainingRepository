


#include "EmCe_HealthComponent.h"

// Sets default values for this component's properties
UEmCe_HealthComponent::UEmCe_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// Initialize variables.

	MaxHealth = 100.0f;
	Health = MaxHealth;
	HealthRegenerationRate = 1.0f;
	HealthRegenerationDelay = 1.0f;

}




// Called when the game starts

void UEmCe_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Turn on health regeneration.

	HealthRegeneration();

	
}


void UEmCe_HealthComponent::HealthRegeneration()
{
	// If health is not full, regenerate health.

	if (Health < MaxHealth)
	{
		Health += HealthRegenerationRate;

		// Set timer to call this function again.

		GetWorld()->GetTimerManager().SetTimer(HealthRegenerationTimerHandle, this, &UEmCe_HealthComponent::HealthRegeneration, HealthRegenerationDelay, false);

		// Display on the screen the current health value using GEngine.

		GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Your actual health : %f"), Health));




	}

	// If health is full, stop regeneration

	if (Health >= MaxHealth)
	{
		Health = MaxHealth;
		GetWorld()->GetTimerManager().ClearTimer(HealthRegenerationTimerHandle);

		// Display on the screen the current health

		UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Health regeneration stopped!"));


	}


}




void UEmCe_HealthComponent::TakeDamage(float Damage)
{

	// If health is greater than 0, take damage

	if (Health > 0)
	{
		// Decrease health by Damage.

		Health -= Damage;

		//Clamp health to 0 and MaxHealth.

		Health = FMath::Clamp(Health, 0.0f, MaxHealth);

		// Display on the screen taking damage message with damage value but without floating point in the damage value.

		GEngine->AddOnScreenDebugMessage(-11, 5.f, FColor::Red, FString::Printf(TEXT("You took damage: %i"), FMath::RoundToInt(Damage)));

		// Display on the screen the current health value.

		GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Red, FString::Printf(TEXT("Your actual health : %f"), Health));

		// If Health is below MaxHealth, start health regeneration.

		if (Health < MaxHealth)
		{
			HealthRegeneration();
		}

		// If health is less than 0, set health to 0

		if (Health < 0)
		{
			Health = 0;
		}


	}

}

// Called every frame
void UEmCe_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

