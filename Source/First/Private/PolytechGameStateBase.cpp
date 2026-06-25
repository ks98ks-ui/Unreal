#include "PolytechGameStateBase.h"
#include "PolytechGameInstance.h" // 추가
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "CoinItem.h"
#include "FirstCharacter1.h"
#include "FirstPlayerController1.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"


APolytechGameStateBase::APolytechGameStateBase()
{
    Score = 0;
    SpawnedCoinCount = 0;
    CollectedCoinCount = 0;
    LevelDuration = 30.f;
    CurrentLevelIndex = 0;
    MaxLevels = 3;
}

void APolytechGameStateBase::BeginPlay()
{
    Super::BeginPlay();

    StartLevel();
    UpdateHUD();

    GetWorldTimerManager().SetTimer(
        HUDUpdateTimerHandle,
        this,
        &APolytechGameStateBase::UpdateHUD,
        0.1f,
        true
    );

}

int32 APolytechGameStateBase::GetScore() const
{
    return Score;
}

void APolytechGameStateBase::AddScore(int32 Amount)
{
    Score += Amount;
}

void APolytechGameStateBase::OnGameOver()
{
    UE_LOG(LogTemp, Warning, TEXT("#### GAME OVER!! ####"));
}

void APolytechGameStateBase::StartLevel()
{
    SpawnedCoinCount = 0;
    CollectedCoinCount = 0;

    TArray<AActor*> FoundVolumes;

    // 레벨 전체에 있는 특정 클래스를 찾아서 FoundVolumes에 추가
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

    // 아이템 몇개 만들지 지정
    const int32 ItemToSpawn = 40;

    for (int32 i = 0; i < ItemToSpawn; i++)
    {
        if (FoundVolumes.Num() > 0)
        {
            // 정확히 어떤 Volume을 쓸건지 Array에서 인덱스로 특정.
            ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);

            if (SpawnVolume)
            {
                AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
                if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
                {
                    // 코인 생성 될 때마다 +1
                    SpawnedCoinCount++;
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Is Not Coin"));
                }
            }
        }
    }

    // 타이머 디자인
    GetWorldTimerManager().SetTimer(
        LevelTimerHandle,
        this,
        &APolytechGameStateBase::OnLevelTimeUp,
        LevelDuration,
        false
    );
    TArray<AActor*>FoundCoins;
    UGameplayStatics::GetAllActorsOfClass(
        GetWorld(),
        ACoinItem::StaticClass(),
        FoundCoins
    );
   
        SpawnedCoinCount = FoundCoins.Num();
 
        UE_LOG(LogTemp, Warning, TEXT("Level %d Start!, Spawned %d coin"),
            CurrentLevelIndex + 1,
            SpawnedCoinCount);
   
}

void APolytechGameStateBase::OnLevelTimeUp()
{
    OnGameOver();
    UE_LOG(LogTemp, Warning, TEXT("Time Out"));
}

void APolytechGameStateBase::OnCoinCollected()
{
    CollectedCoinCount++;

    // 예상 출력로그: Coin Collected: 현재 먹은 수 / 생성된 코인 수
    UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"),
        CollectedCoinCount,
        SpawnedCoinCount);

    if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
    {
        // 코인 다 먹었다는 얘기 (레벨전환 요건 충족)
        EndLevel();
    }
}

// GameState는 현재의 상태. GameMode는 게임의 심판. 
// EndLevel -> Game Over는 GameMode가 판단하므로 EndLevel에서 GameOver->GameMode 내 판정함수 호출.
void APolytechGameStateBase::EndLevel()
{
    // Timer Clear
    GetWorldTimerManager().ClearTimer(LevelTimerHandle);

    UPolytechGameInstance* PolyGI = Cast<UPolytechGameInstance>(GetGameInstance()); // GameInstance 가져오기

    if (!PolyGI) // GameInstance 없으면 게임진행불가
    {
        OnGameOver();
        return;
    }

    // GI의 CurrentLevelIndex를 1 추가
    PolyGI->CurrentLevelIndex++;

    // GI 기준으로 CurrentLevelIndex 갱신
    CurrentLevelIndex = PolyGI->CurrentLevelIndex;

    // CurrentLevelIndex(현재 레벨)가 MaxLevels(끝판)인가? (같거나 큰가)
    if (CurrentLevelIndex >= MaxLevels)
    {
        OnGameOver();
        return;
    }

    // 게임 지속.
    if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
    {
        UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
    }
    else
    {
        OnGameOver();
    }
}

void APolytechGameStateBase::Die()
{
    UE_LOG(LogTemp, Warning, TEXT("#### Die!! ####"));
}

void APolytechGameStateBase::UpdateHUD()
{
    AFirstPlayerController1* FirstPlayerController =
        Cast<AFirstPlayerController1>(GetWorld()->GetFirstPlayerController());

    if (FirstPlayerController)
    {
        UUserWidget* HUDWidget = FirstPlayerController->GetHUDWidget();

        if (HUDWidget)
        {
            if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time"))))
            {
                float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);
                TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
            }

            if (UGameInstance* GameInstance = GetGameInstance())
            {
                if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score"))))
                {
                    UPolytechGameInstance* PolytechGameInstance =
                        Cast<UPolytechGameInstance>(GameInstance);

                    if (PolytechGameInstance)
                    {
                        ScoreText->SetText(FText::FromString(
                            FString::Printf(TEXT("Score: %d"), PolytechGameInstance->TotalScore)
                        ));
                    }
                }
            }
        }
    }
}

