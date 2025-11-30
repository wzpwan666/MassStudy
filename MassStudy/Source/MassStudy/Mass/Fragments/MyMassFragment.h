// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityElementTypes.h"
#include "MyMassFragment.generated.h"

/**
 * 
 */
USTRUCT()
struct MASSSTUDY_API FMyMassFragment : public FMassFragment
{
	GENERATED_BODY()
	
};

USTRUCT()
struct MASSSTUDY_API FSimpleRandomMovementFragment : public FMassFragment
{
	GENERATED_BODY()
public:
	FVector Target;
};
