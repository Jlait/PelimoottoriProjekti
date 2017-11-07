// Fill out your copyright notice in the Description page of Project Settings.


#include "PelimoottoriProjektiGameModeBase.h"
#include "LemmingController.h"

ALemmingController* PlayerControllerClass;
APelimoottoriProjektiGameModeBase::APelimoottoriProjektiGameModeBase(){

	bPauseable = true;
	PlayerControllerClass = ALemmingController::StaticClass();
	HUDClass = AMyHUD::StaticClass();

}


