#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"


//아래 UINTERFACE는 인터페이스를 언리얼 리플렉션 시스템에서 사용하기 위한 기본 매크로
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

//실제 C++클래스 레벨에서 사용할 함수의 원형(시그니처)을 정의
class FIRST_API IItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	//이 아래에 실제 구현이 될 예정인 함수 정의
public:
	// 플레이어가 특정 범주(이 아이템의 지정 범주) 내에 들어 왔을 때 호출
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
	
	// 플레이어가 특정 범주(이 아이템의 지정 범주) 내에 벗어났을 때 호출
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;

	// 이 아이템이 사용되었을 때 호출
	virtual void ActivateItem(AActor* Activator) = 0;
	// 이 아이템의 타입을 반환하는 함수
	virtual FName GetItemType() const = 0;
};
