// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Public/TP_Door.h"
#include "TP_UEGameMode.generated.h"

UCLASS(minimalapi)
class ATP_UEGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Value")
	//UUserWidget* Menu_W;

	bool visibility = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
	ATP_Door* Door;

	int32 count=2;

	UFUNCTION(BlueprintCallable)
	void Menu();

	UFUNCTION(BlueprintCallable)
	void Quit();

	void HitButton();

	ATP_UEGameMode();
};



