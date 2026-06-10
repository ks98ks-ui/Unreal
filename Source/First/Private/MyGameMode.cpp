#include "MyGameMode.h"
#include "FirstCharacter1.h"
#include "FirstPlayerController1.h"
AMyGameMode::AMyGameMode()
{
	//DefaultPawnClass 기본캐릭터가 방금 개발한 AFirstCharacter1로 세팅
	DefaultPawnClass = AFirstCharacter1::StaticClass();

	//player controller 세팅
	PlayerControllerClass = AFirstPlayerController1::StaticClass();

}
