// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "WheelBase.h"

#include "PhysXIncludes.h"
#include "PhysicsPublic.h"
#include "Runtime/Engine/Private/PhysicsEngine/PhysXSupport.h"

UWheelBase::UWheelBase()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	OnCalculateCustomPhysics.BindUObject(this, &UWheelBase::SubstepTick);
}

void UWheelBase::BeginPlay()
{
	Super::BeginPlay();

	PRigidBody = GetBodyInstance()->GetPxRigidBody_AssumesLocked();
}

void UWheelBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetBodyInstance()->AddCustomPhysics(OnCalculateCustomPhysics);
}

void UWheelBase::SubstepTick(float DeltaTime, FBodyInstance* BodyInstance)
{
	// Here get your custom forces
	FVector f = CalculateForce();
	FVector t = CalculateTorque();

	// And apply them to the rigid body
	PRigidBody->addForce(PxVec3(f.X, f.Y, f.Z), physx::PxForceMode::eFORCE, true);
	PRigidBody->addTorque(PxVec3(t.X, t.Y, t.Z), PxForceMode::eFORCE, true);
}

FVector UWheelBase::GetCurrentLocation() {
	PxTransform PTransform = PRigidBody->getGlobalPose();
	return FVector(PTransform.p.x, PTransform.p.y, PTransform.p.z);
}

FRotator UWheelBase::GetCurrentRotation() {
	PxTransform PTransform = PRigidBody->getGlobalPose();
	return FRotator(FQuat(PTransform.q.x, PTransform.q.y, PTransform.q.z, PTransform.q.w));
}

FVector UWheelBase::GetCurrentAngularVelocity() {
	PxVec3 PAngVelocity = PRigidBody->getAngularVelocity();
	return FMath::RadiansToDegrees(FVector(PAngVelocity.x, PAngVelocity.y, PAngVelocity.z));
}

FVector UWheelBase::GetCurrentVelocity() {
	PxVec3 PVelocity = PRigidBody->getLinearVelocity();
	return FVector(PVelocity.x, PVelocity.y, PVelocity.z);
}