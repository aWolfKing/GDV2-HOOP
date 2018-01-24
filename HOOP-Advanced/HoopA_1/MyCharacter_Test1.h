// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter_Test1.generated.h"

UCLASS()
class HOOPA_1_API AMyCharacter_Test1 : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	AMyCharacter_Test1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UCharacterMovementComponent * characterMovement;
	FVector gravityDirection = FVector(0, 0, -1);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float amount);

	void MoveSideways(float amount);

	void RotateCharacter(float amount);

	void RotateBySurface();
	
	void AddGravity();

	void Jump();

};
