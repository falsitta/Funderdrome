// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebugLine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFUNDERDROME_API UDebugLine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDebugLine();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector End;

	UFUNCTION(BlueprintCallable)
	void RedrawLine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
