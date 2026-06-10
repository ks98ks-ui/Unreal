#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UCLASS()
class FIRST_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;  //Tick = 1프레임당 1번

protected:
    // 루트 컴포넌트 선언 포인터
	USceneComponent* SceneRoot;
	
	
	// Staticmesh Component 포인터
	UStaticMeshComponent* StaticMeshComp;

};
