// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_Door.generated.h"

UCLASS()
class TP_UE_API ATP_Door : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

public:	
	// Sets default values for this actor's properties
	ATP_Door();
	inline void OpenDoor() { Destroy(); };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
