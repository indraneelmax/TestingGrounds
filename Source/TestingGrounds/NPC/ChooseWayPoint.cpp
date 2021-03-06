// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"  //TODO Remove these couplings
#include "PatrolRoute.h"


//We are going to implement the Behaviour Tree Task in c++ (not use BP)
//A BTTask needs Execute AI event to start and Finish Execute event to end
//Found the signature from BTTaskNode.h
EBTNodeResult::Type UChooseWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol Points
	auto AIController = OwnerComp.GetAIOwner();
	auto AIPawn = AIController->GetPawn();
	auto PatrolRoute = AIPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute))
	{
		UE_LOG(LogTemp, Warning, TEXT("No Patrol Route component found"));
		return EBTNodeResult::Failed;
	}
	
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Patrol Points are not yet Set on the Actor"));
		return EBTNodeResult::Failed;
	}
	//Set Next WayPoint
	auto BlackBoard = OwnerComp.GetBlackboardComponent();
	auto index = BlackBoard->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoard->SetValueAsObject(WayPoint.SelectedKeyName, PatrolPoints[index]);

	//TODO Safeguard for empty PatrolPoints
	auto len = PatrolPoints.Num();
	auto NewIndex = (index + 1) % len;
	BlackBoard->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);
	UE_LOG(LogTemp, Warning, TEXT("AI Behviour Tree Called! Index value : %d"), index);
	return EBTNodeResult::Succeeded;
}
