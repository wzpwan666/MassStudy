// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMassProcessor.h"
#include "MyMassFragment.h"
#include "MassExecutionContext.h"
#include "MassCommonFragments.h"
#include "MassCommonTypes.h"


UMyMassProcessor::UMyMassProcessor() : EntityQuery(*this)
{

}

void UMyMassProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{

}

void UMyMassProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{

}

USimpleRandomMovementProcessor::USimpleRandomMovementProcessor() : EntityQuery(*this)
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void USimpleRandomMovementProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FSimpleRandomMovementFragment>(EMassFragmentAccess::ReadWrite);
}

void USimpleRandomMovementProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(Context,
		(
			[this](FMassExecutionContext& Context) 
			{
				const TArrayView<FTransformFragment> TransformsList = Context.GetMutableFragmentView<FTransformFragment>();
				const TArrayView<FSimpleRandomMovementFragment> SimpleMovementsList = Context.GetMutableFragmentView<FSimpleRandomMovementFragment>();
				const float WorldDeltaTime = Context.GetDeltaTimeSeconds();
				for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
				{
					FTransform& Transform = TransformsList[EntityIndex].GetMutableTransform();
					FVector& MoveTarget = SimpleMovementsList[EntityIndex].Target;
					FVector CurrentLocation = Transform.GetLocation();
					FVector TargetVector = MoveTarget - CurrentLocation;
					if (TargetVector.Size()<=20.0f){
						MoveTarget = FVector(FMath::RandRange(-1.0f, 1.f) * 1000.f, FMath::RandRange(-1.f, 1.f) * 1000.f, CurrentLocation.Z);
					}
					else {
						Transform.SetLocation(CurrentLocation + TargetVector.GetSafeNormal() * 400.f * WorldDeltaTime);
					}
				}
			}
		)
	);
}
