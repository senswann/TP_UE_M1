// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_TestGameMode.h"
#include "Project_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_TestGameMode::AProject_TestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
