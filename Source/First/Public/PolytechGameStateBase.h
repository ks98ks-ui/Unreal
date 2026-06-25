#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PolytechGameStateBase.generated.h"

UCLASS()
class FIRST_API APolytechGameStateBase : public AGameStateBase
{
    GENERATED_BODY()

public:
    APolytechGameStateBase();
    
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Score;

    //현재 스폰된 코인 개수
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 SpawnedCoinCount;
    // 현재 수집한 코인의 개수
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 CollectedCoinCount;
    // 현재 레벨의 플레이 시간
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    float LevelDuration;
    // 현재 어떤 레벨(basic 0/ medium 1/ hard 2)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 CurrentLevelIndex;
    // 최고 클리어 레벨
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 MaxLevels;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
    TArray<FName> LevelMapNames;

    //게임시간 재는 타이머
    FTimerHandle LevelTimerHandle;
    FTimerHandle HUDUpdateTimerHandle;
    

    UFUNCTION(BlueprintPure, Category = "Score")
    int32 GetScore() const;

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);
    UFUNCTION(BlueprintCallable, Category = "Level")
    void OnGameOver();
    void StartLevel();
    void OnLevelTimeUp();
    void OnCoinCollected();
    void EndLevel();
    void Die();
    void UpdateHUD();


};