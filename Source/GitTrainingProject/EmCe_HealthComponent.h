

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EmCe_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GITTRAININGPROJECT_API UEmCe_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEmCe_HealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Max health of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	// Health of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;

	// Health regeneration rate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthRegenerationRate;

	// Health regeneration delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthRegenerationDelay;

	// Health regeneration function.
	UFUNCTION(BlueprintCallable, Category = "Health")
		void HealthRegeneration();

	// Health regeneration timer handle
	FTimerHandle HealthRegenerationTimerHandle;

	// Take damage function.
	UFUNCTION(BlueprintCallable, Category = "Health")
		void TakeDamage(float Damage);








public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
