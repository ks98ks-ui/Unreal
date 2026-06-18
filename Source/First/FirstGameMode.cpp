#include "FirstGameMode.h"
#include "FirstCharacter1.h"
#include "FirstPlayerController.h"
#include "PolytechGameStateBase.h"

AFirstGameMode::AFirstGameMode()
{
	DefaultPawnClass = AFirstCharacter1::StaticClass();

	PlayerControllerClass = AFirstPlayerController::StaticClass();

	GameStateClass = APolytechGameStateBase::StaticClass();
}
