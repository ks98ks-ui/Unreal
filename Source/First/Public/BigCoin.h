
#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "BigCoin.generated.h"


UCLASS()
class FIRST_API ABigCoin : public ACoinItem
{
	GENERATED_BODY()

public:
	ABigCoin();

	virtual void ActivateItem(AActor* Activator) override;

	
};
