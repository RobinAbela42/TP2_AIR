// Fill out your copyright notice in the Description page of Project Settings.


#include "PacMan.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APacMan::APacMan()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create BoxComponent and set as RootComponent for the Actor
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>("BoxCollision");
	RootComponent = CapsuleCollision;

	// Create StaticMeshComponent and Attach to BoxComponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(CapsuleCollision);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");


}

// Called when the game starts or when spawned
void APacMan::BeginPlay()
{
	Super::BeginPlay();

	Tags.Add("Pacman");
}

// Called every frame
void APacMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(DesiredDirection);
}

// Called to bind functionality to input
void APacMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APacMan::MoveInput);
	}
}

void APacMan::MoveInput(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (MovementVector.X)
	{
		DesiredDirection = FVector(MovementVector.X, 0, 0);
	}
	else if (MovementVector.Y)
	{
		DesiredDirection = FVector(0, MovementVector.Y, 0);
	}
}
