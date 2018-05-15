// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "TestNav.h"


// Sets default values
ATestNav::ATestNav()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestNav::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestNav::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void pathAstar() 
{

}

