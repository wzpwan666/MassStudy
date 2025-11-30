// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MyMassEntityTraitBase.generated.h"

/**
 * 
 */
UCLASS()
class MASSSTUDY_API UMyMassEntityTraitBase : public UMassEntityTraitBase
{
	GENERATED_BODY()
	
};

UCLASS()
class MASSSTUDY_API USimpleRandomMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;

};
