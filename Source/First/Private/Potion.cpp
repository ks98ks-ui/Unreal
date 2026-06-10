
#include "Potion.h"

APotion::APotion()
{
	HealAmount = 10.f;
	ItemType = "Healing";
}

void APotion::ActivateItem(AActor* Activator)
{
	//플레이어의 체력을 amount만큼 회복시키는 로직 등을 구현
	
		if (Activator && Activator->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Player Gained %.1f HP!"), HealAmount));
			DestroyItem();
		}
	}
	
	
