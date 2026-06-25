
#include "MyGameModeBase.h"
#include "FirstCharacter1.h"
#include "FirstPlayerController.h"
#include "PolytechGameStateBase.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AFirstCharacter1::StaticClass();

	PlayerControllerClass = AFirstPlayerController::StaticClass();

	GameStateClass = APolytechGameStateBase::StaticClass();
}
