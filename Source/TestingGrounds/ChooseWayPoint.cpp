// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"



//We are going to implement the Behaviour Tree Task in c++ (not use BP)
//A BTTask needs Execute AI event to start and Finish Execute event to end
//Found the signature from BTTaskNode.h
EBTNodeResult::Type UChooseWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackBoard = OwnerComp.GetBlackboardComponent();
	auto index = BlackBoard->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("AI Behviour Tree Called! Index value : %d"), index);
	return EBTNodeResult::Succeeded;
}
