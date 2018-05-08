// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "DebugLine.h"


// Sets default values for this component's properties
UDebugLine::UDebugLine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	

	// ...
}


void UDebugLine::RedrawLine()
{
	DrawDebugLine(GetWorld(), Start, End, FColor(0, 0, 255), true, -1.0f, 000, 5.0f);
}

// Called when the game starts
void UDebugLine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDebugLine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

