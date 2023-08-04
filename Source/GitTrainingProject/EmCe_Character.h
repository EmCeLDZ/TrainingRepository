

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EmCe_Character.generated.h"

UCLASS()
class GITTRAININGPROJECT_API AEmCe_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmCe_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Left mouse button pressed.

	UFUNCTION(BlueprintCallable, Category = "EmCe_Character")
	void LeftMouseButtonPressed();

	// Right mouse button pressed.

	UFUNCTION(BlueprintCallable, Category = "EmCe_Character")

	void RightMouseButtonPressed();


	// Montage animation.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EmCe_Character")
		class UAnimMontage* AnimMontage;


	// NIagara System.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EmCe_Character")
		class UNiagaraSystem* NiagaraSystem;



	// Effect Sound.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EmCe_Character")
		class USoundBase* Sound;




};
