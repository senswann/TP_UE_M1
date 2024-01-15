// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_Ai.h"

// Sets default values
ATP_Ai::ATP_Ai()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATP_Ai::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_Ai::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATP_Ai::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

