
#include "EmCe_Character.h"
#include <Kismet/GameplayStatics.h>
#include <NiagaraComponent.h>
#include <NiagaraFunctionLibrary.h>



// Sets default values
AEmCe_Character::AEmCe_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize montage animation.

	AnimMontage = nullptr;

	// Initialize particle system.

	NiagaraSystem = nullptr;

	// Initialize sound.

	Sound = nullptr;


}

// Called when the game starts or when spawned
void AEmCe_Character::BeginPlay()
{
	Super::BeginPlay();

	// Print message to screen.

GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using EmCe_Character!"));

// print message to log.

UE_LOG(LogTemp, Warning, TEXT("We are using EmCe_Character!"));

	
	
}

// Called every frame
void AEmCe_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEmCe_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Define mouse input bindings.
	InputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &AEmCe_Character::LeftMouseButtonPressed);
	InputComponent->BindAction("RightMouseButton", IE_Pressed, this, &AEmCe_Character::RightMouseButtonPressed);



}

// Left mouse button pressed.

void AEmCe_Character::LeftMouseButtonPressed()
{
	// Print message to screen.

	GEngine->AddOnScreenDebugMessage(-11, 0.5f, FColor::Blue, TEXT("Triggered C++ Left mouse button function!"));

		// Check if animation is playing.

		if (IsPlayingRootMotion())
		{
			// Print message to screen.

			GEngine->AddOnScreenDebugMessage(-11, 0.5f, FColor::Blue, TEXT("Animation is playing!"));
		}
		else
		{
			// Print message to screen.

			GEngine->AddOnScreenDebugMessage(-11, 0.5f, FColor::Blue, TEXT("Animation is not playing!"));

			// Play montage animation.

			PlayAnimMontage(AnimMontage, 1.0f, FName("DefaultSlot"));

			// Spawn niagara system attached to actor mesh.

			UNiagaraComponent* NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(NiagaraSystem, GetMesh(), FName("DefaultSlot"), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), EAttachLocation::SnapToTarget, true);

			// Play sound.

			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation());
		}



	}










// Right mouse button pressed.

void AEmCe_Character::RightMouseButtonPressed()
{
	// Print message to screen.

	GEngine->AddOnScreenDebugMessage(-11, 0.5f, FColor::Green, TEXT("Triggered C++ Right mouse button function!"));
}

