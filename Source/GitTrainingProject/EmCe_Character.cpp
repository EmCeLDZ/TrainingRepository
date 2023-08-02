
#include "EmCe_Character.h"

// Sets default values
AEmCe_Character::AEmCe_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Left mouse button pressed!"));


}

// Right mouse button pressed.

void AEmCe_Character::RightMouseButtonPressed()
{
	// Print message to screen.

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Right mouse button pressed!"));
}

