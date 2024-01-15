// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_Door.h"

// Sets default values
ATP_Door::ATP_Door()
{
	// Create the static mesh component and set it as the root component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void ATP_Door::BeginPlay()
{
	Super::BeginPlay();
	
}