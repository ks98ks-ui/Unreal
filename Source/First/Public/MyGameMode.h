#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	//만든 캐릭터가 기본 캐릭터로 설정되어 스폰되도록 세팅.

public:
	//생성자 함수 선운
	AMyGameMode();

	
};
