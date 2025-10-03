// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PacMan.generated.h"

UCLASS()
class TP2_AIR_API APacMan : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CapsuleCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UFloatingPawnMovement* FloatingPawnMovement;
	
protected:
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	class UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	class UInputAction* MoveAction;
	
	void MoveInput(const FInputActionValue& Value);

	FVector DesiredDirection = FVector(0,0,0);

	UPROPERTY(EditAnywhere, Category="Speed")
	float Speed=5000;

};
