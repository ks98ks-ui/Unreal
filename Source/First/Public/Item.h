#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FIRST_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// 루트 컴포넌트 선언 포인터 < 찍은곳으로 가는 주소 가져오기 ex) SceneRoot에 USceneComponent주소 넣기
	USceneComponent* SceneRoot;
	
	
	// Staticmesh Component 포인터
	UStaticMeshComponent* StaticMeshComp;
	UAudioComponent* AudioComp;


};
