// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"



//UCanvas* Canvas;


AMyHUD::AMyHUD() {

}

void AMyHUD::DrawHUD() 
{
	if (bStartSelecting == true) {

		if (FoundActors.Num() > 0) 
		{
			for (int32 i = 0; i < FoundActors.Num(); i++) {
				FoundActors[i]->DeSelected();
			}
		}
	FoundActors.Empty();

	CurrentPoint = GetMousePos2D();
	DrawRect(FLinearColor(0, 0, 1, .15f), InitialPoint.X, InitialPoint.Y,
		CurrentPoint.X - InitialPoint.X, CurrentPoint.Y - InitialPoint.Y);

	GetActorsInSelectionRectangle<ALemming>(InitialPoint, CurrentPoint, FoundActors, false, false);

	if (FoundActors.Num() > 0) {
		for (int32 i = 0; i < FoundActors.Num(); i++) {
			FoundActors[i]->IsSelected();
		}
	}


	}
}

void AMyHUD::BeginPlay() {

}

FVector2D AMyHUD::GetMousePos2D() {

	float posX;
	float posY;

	GetOwningPlayerController()->GetMousePosition(posX, posY);

	return FVector2D(posX, posY);
}

