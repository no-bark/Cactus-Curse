// Fill out your copyright notice in the Description page of Project Settings.
#include "FPSProj.h"
#include "FPSGameMode.h"
#include "FPSCharacter.h"
#include "CustomReticle.h"

AFPSGameMode::AFPSGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = AFPSCharacter::StaticClass();
	HUDClass = ACustomReticle::StaticClass();//ConstructorHelpers::FClassFinder<UClass>("/Game/Content/Blueprints/HUDClass");// ::StaticClass();
}


// Note that engine version 4.3 changed the method's name to StartPlay(), because of this engine versions before 4.3, or older tutorials, use BeginPlay()
void AFPSGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}