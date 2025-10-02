// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Referee.generated.h"

/**
 * 
 */
UCLASS()
class TP2_AIR_API UReferee : public UGameInstance
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere)
	int32 Score = 0;

	void AddScore();
};
