// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FunderdromeSpawnpointBase.h"
#include "FunderdromeMasterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYFUNDERDROME_API AFunderdromeMasterGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
public:
	//UFUNCTION(EditAnywhere, BlueprintReadWrite, Category="Spawns")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawns")
	TArray<TSubclassOf<AFunderdromeSpawnpointBase>> FunderdromeSpawnPoints;

private:
	
};
