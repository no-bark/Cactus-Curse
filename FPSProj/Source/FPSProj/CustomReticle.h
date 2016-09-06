// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "CustomReticle.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ReticleType : uint8
{
	Eye 	UMETA(DisplayName = "Eye"),
	Hand 	UMETA(DisplayName = "Hand"),
	None	UMETA(DisplayName = "None")
};

/**
 * 
 */
UCLASS()
class FPSPROJ_API ACustomReticle : public AHUD
{
	GENERATED_BODY()

	ACustomReticle(const class FObjectInitializer& PCIP);
	
	UPROPERTY()
	UTexture2D* textToDraw;

	UPROPERTY()
	UTexture2D* possibleTextures[5] = { };

	virtual void DrawHUD() override;

public:
	UFUNCTION()
		void UpdateReticle(ReticleType which = ReticleType::Eye);
};
