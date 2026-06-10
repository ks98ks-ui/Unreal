#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

UCLASS()
class FIRST_API AMineItem : public ABaseItem
{
	GENERATED_BODY()
	

public:

	AMineItem();

	//폭발까지 3초 딜레이
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDelay;

	//폭발범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionRadius;

	//폭발데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDamage;

	virtual void ActivateItem(AActor* Activator) override;

	//작동된적 있는지 확인
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mine")
	bool bIsActivated;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* ExplosionCollision;

	//지뢰발동 타이머세팅

	FTimerHandle ExplosionTimerHandle;

	void  Explode();


};
