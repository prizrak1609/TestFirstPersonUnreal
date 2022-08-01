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
	UPROPERTY(EditAnywhere)
	float Scale;

	UPROPERTY(EditAnywhere)
	UMaterial* Material;

	void PostInitializeComponents() override;

	void BeginPlay() override;

#if WITH_EDITOR
	void PostLoad() override;

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

private:
	UMaterialInstanceDynamic* dynMaterial;
	UStaticMeshComponent* plane;

};
