
#include "SmallCoin.h"

ASmallCoin::ASmallCoin()
{
	PointValue = 10;
	ItemType = "SmallCoin";
}

void ASmallCoin::ActivateItem(AActor * Activator)
{
	Super::ActivateItem(Activator);
}
