// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_UEGameMode.h"
#include "TP_UECharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ATP_UEGameMode::ATP_UEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void ATP_UEGameMode::Menu()
{
    UE_LOG(LogTemp, Warning, TEXT("Menu"));
    /*if (visibility) {
        Menu_W->SetVisibility(ESlateVisibility::Visible);
    }
    else {
        Menu_W->SetVisibility(ESlateVisibility::Hidden);
    }*/
    visibility = !visibility;
}

void ATP_UEGameMode::Quit()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

    if (PlayerController)
    {
        PlayerController->ConsoleCommand("Quit");
    }
}

void ATP_UEGameMode::HitButton()
{
    count--;
    if (count <= 0) {
        Door->OpenDoor();
    }
}
