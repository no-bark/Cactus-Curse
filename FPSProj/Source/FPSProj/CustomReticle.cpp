// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProj.h"
#include "CustomReticle.h"

ACustomReticle::ACustomReticle(const class FObjectInitializer& PCIP) : Super(PCIP)
{ 
	static ConstructorHelpers::FObjectFinder<UTexture2D> HUDReticle(TEXT("/Game/Material/eyereticle"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> BADReticle(TEXT("/Game/Material/testReticle"));
	textToDraw = HUDReticle.Object;	

	possibleTextures[0] = HUDReticle.Object;
	possibleTextures[1] = BADReticle.Object;
	//if (!HUDReticle.Succeeded())
	//{
	//	if (GEngine)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("What the Fck"));
	//	}
	//}
}

void ACustomReticle::DrawHUD()
{
	FVector2D ScreenDim = FVector2D(Canvas->SizeX, Canvas->SizeY);
	//
	Super::DrawHUD();
	//
	if (textToDraw != NULL)
	{
		DrawTexture(textToDraw, (ScreenDim.X / 2) - 25, (ScreenDim.Y / 2) - 25, 50, 50, 0.0f, 0.0f, 1.0f, 1.0f, FLinearColor::White, BLEND_Translucent, 1);
	}
}

void ACustomReticle::UpdateReticle(ReticleType which)
{
	switch (which)
	{
	case ReticleType::Eye:
		textToDraw = possibleTextures[0];
		break;
	case ReticleType::None:
		textToDraw = possibleTextures[2];
		break;
	case ReticleType::Hand:
		textToDraw = possibleTextures[1];
		break;
	default:
		break;
	}
}