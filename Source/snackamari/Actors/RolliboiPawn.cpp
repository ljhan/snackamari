// Fill out your copyright notice in the Description page of Project Settings.

#include "RolliboiPawn.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Components/SceneComponent.h"
#include "snackamari/Actors/RolliPawnMovementComponent.h"

// Sets default values
ARolliboiPawn::ARolliboiPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rolliball"));
	RootComponent = mesh;
	camAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("camAnchor"));
	camAnchor->SetupAttachment(RootComponent);
	camAnchor->bAbsoluteRotation = true;
	movementComponent = CreateDefaultSubobject<URolliPawnMovementComponent>(TEXT("movementComponent"));
	movementComponent->UpdatedPrimitive = mesh;
	

}

// Called when the game starts or when spawned
void ARolliboiPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARolliboiPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARolliboiPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UPawnMovementComponent * ARolliboiPawn::GetMovementComponent() const
{
	return movementComponent;
}

void ARolliboiPawn::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce) {
	movementComponent->AddInputVector(WorldDirection*ScaleValue, bForce);
}
