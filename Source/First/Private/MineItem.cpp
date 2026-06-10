
#include "MineItem.h"
#include "Components/SphereComponent.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 3.0f;
	ExplosionRadius = 300.f;
	ExplosionDamage = 30.f;
	ItemType = "Mine";
	bIsActivated = false;
	
	//mine전용 셋업
	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);
}

void AMineItem::ActivateItem(AActor* Activator)
{
	// 지뢰를 사용한다고 가정했을 때의 로직
	//3초 후 폭발 실행
	GetWorld()->GetTimerManager().SetTimer(
		ExplosionTimerHandle, 
		this, 
		&AMineItem::Explode, 
		ExplosionDelay);
	
	
}

void AMineItem::Explode()
{
	//지뢰의 메인 기능을 설계
	TArray<AActor*>OverlappingActors;
	ExplosionCollision->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Player Damaged %.1f by MineItem"), ExplosionDamage));
		}
	}

	// 지뢰 제거
	DestroyItem();
}

