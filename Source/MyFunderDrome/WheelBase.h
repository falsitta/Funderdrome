// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/PrimitiveComponent.h"
#include "WheelBase.generated.h"

/**
 * 
 */
UCLASS(abstract)
class MYFUNDERDROME_API UWheelBase : public UPrimitiveComponent
{
	GENERATED_BODY()
	
	
public:
	UWheelBase();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual FVector CalculateForce() PURE_VIRTUAL(UWheelBase::CalculateForce, return FVector(0, 0, 0););
	virtual FVector CalculateTorque() PURE_VIRTUAL(UWheelBase::CalculateTorque, return FVector(0, 0, 0););

	FCalculateCustomPhysics OnCalculateCustomPhysics;

	void SubstepTick(float DeltaTime, FBodyInstance* BodyInstance);

	physx::PxRigidBody* PRigidBody;

	FORCEINLINE FVector  GetCurrentLocation();
	FORCEINLINE FRotator GetCurrentRotation();
	FORCEINLINE FVector  GetCurrentVelocity();
	FORCEINLINE FVector  GetCurrentAngularVelocity();

};
