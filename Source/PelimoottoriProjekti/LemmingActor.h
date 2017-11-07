// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PelimoottoriProjekti.h"
#include "GameFramework/Actor.h"
#include "LemmingActor.generated.h"

UCLASS()
class PELIMOOTTORIPROJEKTI_API ALemmingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALemmingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
