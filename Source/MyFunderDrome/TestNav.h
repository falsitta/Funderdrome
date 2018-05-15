// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestNav.generated.h"

/*struct Node
{
	Node& Parent;
	TArray<Node> Links;
	float FCost;
	int32 NodeIndex;
}
*/

UCLASS()
class MYFUNDERDROME_API ATestNav : public AActor
{
	GENERATED_BODY()

public:
	//public function to get the final result path.
	TArray<FVector> GetPath(FVector& Start, FVector& end);

	
public:	
	// Sets default values for this actor's properties
	ATestNav();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
