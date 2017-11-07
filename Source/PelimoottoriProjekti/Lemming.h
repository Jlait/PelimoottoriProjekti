// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "PelimoottoriProjekti.h"
#include "Lemming.generated.h"


UCLASS()
class PELIMOOTTORIPROJEKTI_API ALemming : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALemming();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void IsSelected();

	void DeSelected();


	bool selected;

	UStaticMeshComponent* SphereVisual;

	// PlayerController
	//ALemmingController* PlayerControllerClass;

	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;
};