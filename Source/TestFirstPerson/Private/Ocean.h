// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Ocean.generated.h"

/**
 * 
 */
UCLASS()
class AOcean : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	void PostInitializeComponents() override;

	void BeginPlay() override;
};
