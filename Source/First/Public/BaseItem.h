#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h" // ItemInterface인터페이스 포함시키기
#include "BaseItem.generated.h"

class USphereComponent;


UCLASS()
class FIRST_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//아이템 유형(타입)을 편집 가능하게 지정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;//자손클래스 또는 언리얼 에디터에서 Coin, Trap, Potion등등으로 정의해서 사용할 수 있게 선언

	//IItemInterface 에서 요구하는 함수들을 구현
		// 플레이어가 특정 범주(이 아이템의 지정 범주) 내에 들어 왔을 때 호출
	UFUNCTION()
	virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;
	UFUNCTION()
	// 플레이어가 특정 범주(이 아이템의 지정 범주) 내에 벗어났을 때 호출
	virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;
	// 이 아이템이 사용되었을 때 호출
	virtual void ActivateItem(AActor* Activator) override;
	// 이 아이템의 타입을 반환하는 함수
	virtual FName GetItemType() const override;

	//아이템을 제거하는 공통 함수 구현(추가 이펙트 또는 로직 넣을수 있음)
	virtual void DestroyItem();

	//루트컴포넌트(씬)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USceneComponent* Scene;

	//충돌컴포넌트

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* Collision;

	//아이템 시각표현용 스태틱메시
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
