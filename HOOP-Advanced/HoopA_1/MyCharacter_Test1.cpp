// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter_Test1.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter_Test1::AMyCharacter_Test1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	characterMovement = GetCharacterMovement();

}

// Called when the game starts or when spawned
void AMyCharacter_Test1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter_Test1::Tick(float DeltaTime)
{

	//FVector velocity = GetCharacterMovement()->Velocity;
	//velocity = FVector::VectorPlaneProject(velocity, -GetActorUpVector());
	//velocity += -GetActorUpVector() * 9.81f * 50;
	//GetCharacterMovement()->Velocity = velocity;

	AddGravity();

	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter_Test1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &AMyCharacter_Test1::MoveForward);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMyCharacter_Test1::MoveSideways);
	PlayerInputComponent->BindAxis("MouseX", this, &AMyCharacter_Test1::RotateCharacter);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter_Test1::Jump);
}


void AMyCharacter_Test1::MoveForward(float amount) {

	if (Controller && amount) {
		AddMovementInput(GetActorForwardVector(), amount);
			RotateBySurface();
	}

}

void AMyCharacter_Test1::MoveSideways(float amount) {

	if (Controller && amount) {
		AddMovementInput(GetActorRightVector(), amount);
			RotateBySurface();
	}

}

void AMyCharacter_Test1::RotateCharacter(float amount) {

	if (Controller && amount) {
		AddControllerYawInput(amount);
			RotateBySurface();
	}

}


void AMyCharacter_Test1::RotateBySurface() {

	FVector sourceDir = gravityDirection*100;
	FVector source = GetActorLocation() + (sourceDir * 0.9f);
	FVector traceEnd = source + (sourceDir * 0.3f);

	FCollisionQueryParams collisionParams;

	DrawDebugPoint(GetWorld(), GetActorLocation(), 4.0f, FColor::Green, false, 2.0f, 0);

	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + -GetActorUpVector(), FColor::Cyan, false, 2.0f, 0, 1.0f);

	DrawDebugLine(
		GetWorld(),
		source,
		traceEnd,
		FColor::Red,
		false,
		0.2f,
		0,
		1
	);


	FHitResult hit(ForceInit);
	if (GetWorld()->LineTraceSingleByChannel(hit, source, traceEnd, ECollisionChannel::ECC_Visibility, collisionParams)) {

		UE_LOG(LogTemp, Warning, TEXT("Your message"));

		//FMatrix rMatrix = FMatrix( FVector::VectorPlaneProject(GetActorForwardVector(),hit.ImpactNormal), FVector::VectorPlaneProject(GetActorRightVector(),hit.ImpactNormal), hit.ImpactNormal, FVector::ZeroVector);
		gravityDirection = -hit.ImpactNormal;

		//SetActorRotation(rMatrix.Rotator());
	}



	FMatrix rMatrix = FMatrix(FVector::VectorPlaneProject(GetActorForwardVector(), -gravityDirection), FVector::VectorPlaneProject(GetActorRightVector(), -gravityDirection), -gravityDirection, FVector::ZeroVector);

	SetActorRotation(/*rMatrix.Rotator()*/ FMath::Lerp(GetActorRotation(), rMatrix.Rotator(), 0.2f));


}


void AMyCharacter_Test1::AddGravity() {
	
	/*
	FVector velocity = characterMovement->Velocity;
	velocity += gravityDirection * 9.81f;
	characterMovement->Velocity = velocity;
	*/

	characterMovement->AddForce(gravityDirection * 9.81f * 10000);
	
}


void AMyCharacter_Test1::Jump() {

	characterMovement->AddImpulse(GetActorUpVector() * 9.81f * 5000);

}
