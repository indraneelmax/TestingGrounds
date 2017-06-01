// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrolGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrolGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Path")
	TArray<AActor*> PatrolPoints_CPP;
	
	
};
