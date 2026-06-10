#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "Potion.generated.h"


UCLASS()
class FIRST_API APotion : public ABaseItem
{
	GENERATED_BODY()
public:
	APotion();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealAmount;
	virtual void ActivateItem(AActor* Activator) override;

};
