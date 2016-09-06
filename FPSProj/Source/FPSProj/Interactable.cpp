// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProj.h"
#include "Interactable.h"


// Sets default values for this component's properties
UInteractable::UInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInteractable::Hover()
{
	//UE_LOG(LogTemp, Warning, TEXT("Debug! We hit this:"));
	
	APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	Cast<ACustomReticle>(PC->GetHUD())->UpdateReticle(hoverImage);
}

// Called every frame
void UInteractable::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

