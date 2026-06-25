
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PolytechGameInstance.generated.h"


UCLASS()
class FIRST_API UPolytechGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPolytechGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 TotalScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);

};
