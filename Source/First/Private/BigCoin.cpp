
#include "BigCoin.h"

ABigCoin::ABigCoin()
{
	PointValue = 50;
	ItemType = "BigCoin";
}

void ABigCoin::ActivateItem(AActor * Activator)
{
	 //아이템 소멸
	Super::ActivateItem(Activator);
}
