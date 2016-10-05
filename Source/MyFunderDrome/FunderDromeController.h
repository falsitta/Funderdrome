// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "FunderDromeController.generated.h"

/**
 * 
 */
UCLASS()
class MYFUNDERDROME_API AFunderDromeController : public APlayerController
{
	GENERATED_BODY()

		virtual void PawnLeavingGame() override;

	
	
};
