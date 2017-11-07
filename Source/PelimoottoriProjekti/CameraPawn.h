// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PelimoottoriProjekti.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class PELIMOOTTORIPROJEKTI_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

//	AMyHUD* HUDPtr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
		USceneComponent* RootScene;


	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY()
	UCameraComponent* cameraComponent;

	UPROPERTY()
		APlayerController*  playerController;

	//UMovementComponent* movementComponent;

	UFUNCTION()
		FVector GetCameraPanDirection();

	UPROPERTY()
		float margin = 10;

	UPROPERTY()
	int32 screenSizeX;

	UPROPERTY()
	int32 screenSizeY;

	UPROPERTY()
	float scrollSpeed = 2;

	//FVector2D mousePos;
	//FVector2D ViewportSize;
	
};
