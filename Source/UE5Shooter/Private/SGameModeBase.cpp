// THEY. All Rights Reserved.


#include "SGameModeBase.h"
#include "Player/SPlayerController.h"
#include "Player/SBaseCharacter.h"

ASGameModeBase::ASGameModeBase()
{
    DefaultPawnClass = ASBaseCharacter::StaticClass();
    PlayerControllerClass = ASPlayerController::StaticClass();
}
