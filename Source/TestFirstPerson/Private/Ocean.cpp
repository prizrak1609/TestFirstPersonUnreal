// Fill out your copyright notice in the Description page of Project Settings.


#include "Ocean.h"

void AOcean::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	plane = Cast<UStaticMeshComponent>(GetRootComponent());

	dynMaterial = plane->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Material);
}

void AOcean::BeginPlay()
{
	Super::BeginPlay();

	dynMaterial->SetScalarParameterValue(TEXT("Scale"), Scale);
	plane->SetMaterial(0, dynMaterial);
}

#if WITH_EDITOR
void AOcean::PostLoad()
{
	Super::PostLoad();

	plane = Cast<UStaticMeshComponent>(GetRootComponent());

	dynMaterial = plane->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Material);
}

void AOcean::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(AOcean, Scale))
	{
		dynMaterial->SetScalarParameterValue(TEXT("Scale"), Scale);
		plane->SetMaterial(0, dynMaterial);
	}
}
#endif WITH_EDITOR
