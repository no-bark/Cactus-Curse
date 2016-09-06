// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CustomReticle.h"
#include "Interactable.generated.h"


UCLASS(Blueprintable)
class FPSPROJ_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractable();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere, Category = "Switch Components")
	ReticleType hoverImage;

	UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
	void Hover();
};
