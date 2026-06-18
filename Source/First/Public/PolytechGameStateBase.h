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

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Score;

    UFUNCTION(BlueprintPure, Category = "Score")
    int32 GetScore() const;

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);
};