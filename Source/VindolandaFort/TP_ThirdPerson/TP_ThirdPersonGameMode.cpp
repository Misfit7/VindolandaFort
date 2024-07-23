// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonGameMode.h"
#include "TP_ThirdPersonCharacter.h"
#include "GameFramework/PlayerState.h"
#include "UObject/ConstructorHelpers.h"

ATP_ThirdPersonGameMode::ATP_ThirdPersonGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
    static ConstructorHelpers::FClassFinder<APlayerController> ACustomPlayerController(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonPlayerController"));
    if (ACustomPlayerController.Class != NULL)
    {
        PlayerControllerClass = ACustomPlayerController.Class;
    }
    static ConstructorHelpers::FClassFinder<APlayerState> ACustomPlayerState(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonPlayerState"));
    if (ACustomPlayerState.Class != NULL)
    {
        PlayerStateClass = ACustomPlayerState.Class;
    }
}
