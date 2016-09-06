// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProj.h"
#include "FPSCharacter.h"
#include "CustomReticle.h"
#include "Interactable.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using FPSCharacter!"));
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APlayerController* PC = Cast<APlayerController>(Controller);
	FVector fwd = PC->GetActorForwardVector();
	FVector start = FVector();
	FVector orStart = FVector();
	FRotator looking = FRotator();
	orStart = GetActorLocation();
	GetActorEyesViewPoint(start, looking);

	FHitResult Impact;
	FVector end = start + (fwd * 10000);
	if (!GetWorld()->LineTraceSingleByChannel(Impact, start + fwd * 50, end, ECollisionChannel::ECC_MAX, FCollisionQueryParams(TEXT("ProjClient"), true, Instigator)))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Debug! We hit nothing!"));
		// failsafe  
		Impact.ImpactPoint = GetActorLocation();
		Impact.ImpactNormal = -fwd;

		NonInteract();
	}

	else
	{
		//DrawDebugSphere(GetWorld(), Impact.ImpactPoint, 20, 6, FColor::Green);
		
		UInteractable* Inters;
		Inters = Impact.Actor.Get()->FindComponentByClass<UInteractable>();

		if (Inters != NULL)
		{
			Inters->Hover();
		}
		else
		{
			NonInteract();
		}
	}
}

void AFPSCharacter::NonInteract()
{
	APlayerController* PC = Cast<APlayerController>(Controller);
	Cast<ACustomReticle>(PC->GetHUD())->UpdateReticle(ReticleType::None);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	InputComponent->BindAxis("SideToSide", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("UpAndDown", this, &AFPSCharacter::AddControllerPitchInput);

	InputComponent->BindAction("ChangeRet", IE_Pressed, this, &AFPSCharacter::ChangeReticle);
	InputComponent->BindAction("ChangeNothing", IE_Pressed, this, &AFPSCharacter::ChangeNothing);
}

void AFPSCharacter::ChangeReticle()
{
	APlayerController* PC = Cast<APlayerController>(Controller);
	Cast<ACustomReticle>(PC->GetHUD())->UpdateReticle();
	
}

void AFPSCharacter::ChangeNothing()
{
	APlayerController* PC = Cast<APlayerController>(Controller);
	Cast<ACustomReticle>(PC->GetHUD())->UpdateReticle(ReticleType::Hand);
}

void AFPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f) )
	{
		//find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit the pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		//add Movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}