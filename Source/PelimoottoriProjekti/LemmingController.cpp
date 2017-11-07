// Fill out your copyright notice in the Description page of Project Settings.

#include "LemmingController.h"
#include "PelimoottoriProjekti.h"



ALemmingController::ALemmingController()
{

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

}

void ALemmingController::BeginPlay() 
{
	HUDPtr = Cast<AMyHUD>(GetHUD());

}

void ALemmingController::SetupInputComponent() 
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ALemmingController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ALemmingController::SelectionReleased);

	InputComponent->BindAction("RightMouseClick", IE_Released, this, &ALemmingController::MoveReleased);

}

void ALemmingController::SelectionPressed() 
{
	HUDPtr->InitialPoint = HUDPtr->GetMousePos2D();
	HUDPtr->bStartSelecting = true;
}

void ALemmingController::SelectionReleased() {
	HUDPtr->bStartSelecting = false;
	SelectedActors = HUDPtr->FoundActors;
	
}

void ALemmingController::MoveReleased() {
	if (SelectedActors.Num() > 0)
	{
		for (int32 i = 0; i < SelectedActors.Num(); i++) 
		{
			FHitResult hit;
			GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hit);
			FVector MoveLocation = hit.Location;//+ FVector(i / 2 * 100, i % 2 * 100, 0);
			UNavigationSystem::SimpleMoveToLocation(SelectedActors[i]->GetController(),
				MoveLocation);
			DrawDebugSphere(GetWorld(), MoveLocation, 25, 10, FColor::Green, false, 3);
			UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"),
				*MoveLocation.ToString());
	
		}

	}
}