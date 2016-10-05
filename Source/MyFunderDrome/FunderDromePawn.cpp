// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "FunderDromePawn.h"


// Sets default values
AFunderDromePawn::AFunderDromePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFunderDromePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFunderDromePawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AFunderDromePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}




