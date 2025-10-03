// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ghost.h"
#include "Blinky.generated.h"

/**
 * 
 */
UCLASS()
class TP2_AIR_API ABlinky : public AGhost
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="AI")
	class UBehaviorTree* BehaviorTree;
	
};
