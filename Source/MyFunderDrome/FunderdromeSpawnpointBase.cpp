// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "FunderdromeSpawnpointBase.h"


// Sets default values
AFunderdromeSpawnpointBase::AFunderdromeSpawnpointBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFunderdromeSpawnpointBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFunderdromeSpawnpointBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

