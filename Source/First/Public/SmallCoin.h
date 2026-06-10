#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "SmallCoin.generated.h"


UCLASS()
class FIRST_API ASmallCoin : public ACoinItem
{
	GENERATED_BODY()
	
public:
	ASmallCoin();

	virtual void ActivateItem(AActor* Activator) override;
};
