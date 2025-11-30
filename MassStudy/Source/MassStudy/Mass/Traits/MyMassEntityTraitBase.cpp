// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMassEntityTraitBase.h"
#include "MyMassFragment.h"
#include "MassEntityTemplateRegistry.h"

void USimpleRandomMovementTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.AddFragment<FSimpleRandomMovementFragment>();
}
