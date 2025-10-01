// Fill out your copyright notice in the Description page of Project Settings.


#include "PacMan.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APacMan::APacMan()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create BoxComponent and set as RootComponent for the Actor
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	// Create StaticMeshComponent and Attach to BoxComponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);
	

}

// Called when the game starts or when spawned
void APacMan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(DesiredDirection);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Moving to : %s"), *DesiredDirection.ToString()));

	

}

// Called to bind functionality to input
void APacMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if ( APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if ( UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Started, this, &APacMan::MoveInput);
	}
	

}

void APacMan::MoveInput(const FInputActionValue& Value )
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("vector %s"), *MovementVector.ToString()));

	DesiredDirection = FVector(MovementVector.X, MovementVector.Y, 0);
	

}