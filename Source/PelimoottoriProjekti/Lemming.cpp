// Fill out your copyright notice in the Description page of Project Settings.


#include "Lemming.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LemmingController.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"

#include "Components/SphereComponent.h"
FVector forward = FVector(10, 0, 0);

//ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));


// Sets default values
ALemming::ALemming()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bStartWithTickEnabled = true;
	CursorToWorld->SetVisibility(false);

}

// Called when the game starts or when spawned
void ALemming::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void ALemming::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALemming::IsSelected() {
	CursorToWorld->SetVisibility(true);
}

void ALemming::DeSelected() {
	CursorToWorld->SetVisibility(false);
}

// Called to bind functionality to input
/*
void ALemming::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALemming::GetController() {
PlayerControllerClass = ALemmingController::StaticClass();
}
*/

