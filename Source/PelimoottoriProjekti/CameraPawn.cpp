// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "PelimoottoriProjekti.h"



// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootScene);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-50, 0, 0));

	// Kamera
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	playerController = Cast<APlayerController>(GetController());
	playerController->GetViewportSize(screenSizeX, screenSizeY);

}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(GetCameraPanDirection() * scrollSpeed);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector ACameraPawn::GetCameraPanDirection() 
{
	float mousePosX;
	float mousePosY;

	float camDirectionX = 0;
	float camDirectionY = 0;
	
	playerController->GetMousePosition(mousePosX, mousePosY);

	// Vasen reuna
	if (mousePosX <= margin) {
		camDirectionY = -1;
	}

	if (mousePosY <= margin) {
		camDirectionX = 1;
	}

	// Oikea reuna
	if (mousePosX >= screenSizeX - margin) {
		camDirectionY = 1;
	}

	if (mousePosY >= screenSizeY - margin) {
		camDirectionX = -1;
	}

	return FVector(camDirectionX, camDirectionY, 0);
}