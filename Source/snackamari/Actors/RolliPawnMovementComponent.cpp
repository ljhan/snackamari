// Fill out your copyright notice in the Description page of Project Settings.

#include "RolliPawnMovementComponent.h"
#include "Classes/Components/PrimitiveComponent.h"

URolliPawnMovementComponent::URolliPawnMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.SetTickFunctionEnable(true);
	RollTorque = 1000000.f;
}

#pragma optimize("", off)
void URolliPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedPrimitive || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	FVector right = FVector::CrossProduct(ConsumeInputVector(), FVector::UpVector);

	UpdatedPrimitive->AddTorque(right*RollTorque*DeltaTime);
}
#pragma optimize("", on)