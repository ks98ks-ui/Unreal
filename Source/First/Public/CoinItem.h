#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "CoinItem.generated.h"

UCLASS()
class FIRST_API ACoinItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	ACoinItem();
protected:
	//코인 획득시 얻을 점수 구체적인 점수는 자손클래스에서 정의
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 PointValue;

	//부모클래스의 ActivateItem 함수를 오버라이드
	virtual void ActivateItem(AActor* Activator) override;
};
