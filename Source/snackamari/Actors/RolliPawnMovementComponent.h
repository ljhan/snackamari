// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "RolliPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class SNACKAMARI_API URolliPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	URolliPawnMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rolling")
		float RollTorque;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
};
