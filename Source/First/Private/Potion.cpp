
#include "Potion.h"
#include "FirstCharacter1.h"


APotion::APotion()
{
	HealAmount = 20.f;
	ItemType = "Healing";
}

void APotion::ActivateItem(AActor* Activator)
{
	//플레이어의 체력을 amount만큼 회복시키는 로직 등을 구현
	
		if (Activator && Activator->ActorHasTag("Player"))
		{
			if (AFirstCharacter1* FirstCharacter1 = Cast<AFirstCharacter1>(Activator))
			{
				// 캐릭터의 체력 회복
				FirstCharacter1->AddHealth(HealAmount);
			}

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Player Gained %.1f HP!"), HealAmount));
			DestroyItem();
		}
	}
	
	
