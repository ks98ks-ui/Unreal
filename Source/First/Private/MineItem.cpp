
#include "MineItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

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
			//데미지 발생시켜 Actor의 TakeDamage()을 실행
			UGameplayStatics::ApplyDamage(
				Actor,                             //데미지 받을 액터
				ExplosionDamage,                   //데미지 크기
				nullptr,                           //데미지 유발한 주체
				this,                              //데미지를 유발하는 오브젝트
				UDamageType::StaticClass()         //데미지 유형
			);

			// 공격사실 알림로그
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Player Damaged %.1f by MineItem"), ExplosionDamage));
		}
	}

	// 지뢰 제거
	DestroyItem();
}

