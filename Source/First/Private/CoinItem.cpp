
#include "CoinItem.h"
#include "Engine/World.h"
#include "PolytechGameStateBase.h"

ACoinItem::ACoinItem()
{
// 부모단계에서 필요한 프로퍼티 등이 있을경우 작성
}

void ACoinItem::ActivateItem(AActor* Activator)
{
    // 플레이어 태그 확인
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (APolytechGameStateBase* GameState = World->GetGameState<APolytechGameStateBase>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected(); //GameState 의 OnCoinCollected를 작동시켜서 코인획득을 알림
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!! :: COIN")));
			}
		}
		//아이템 파괴 함수 호출
		DestroyItem();
	}
}
