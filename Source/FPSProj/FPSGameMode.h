// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h" //for version 4.4+
#include "GameFramework/GameMode.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJ_API AFPSGameMode : public AGameMode
{
	GENERATED_BODY()

	AFPSGameMode(const FObjectInitializer& ObjectInitializer);
	
	virtual void StartPlay() override;
};
