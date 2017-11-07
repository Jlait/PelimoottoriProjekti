// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DrawDebugHelpers.h"
#include "MyHUD.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "LemmingController.generated.h"

/**
 * 
 */
UCLASS()
class PELIMOOTTORIPROJEKTI_API ALemmingController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ALemmingController();
	
	
public:
	
	virtual	void BeginPlay() override;

	virtual	void SetupInputComponent() override;

	AMyHUD* HUDPtr;

private:
	TArray <ALemming*> SelectedActors;

protected:

	void SelectionPressed();

	void SelectionReleased();

	void MoveReleased();

};
