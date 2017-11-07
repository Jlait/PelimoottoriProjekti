// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PelimoottoriProjekti.h"
#include "Lemming.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class PELIMOOTTORIPROJEKTI_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	virtual void DrawHUD() override; // Same as tick

	FVector2D InitialPoint; // Piste kun hiirt‰ painetaan 
	FVector2D CurrentPoint; // Piste kun hiiri pidet‰‰n painettuna

	FVector2D GetMousePos2D();

	bool bStartSelecting = false;

	TArray <ALemming*> FoundActors;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
