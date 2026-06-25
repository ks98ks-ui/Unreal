#include "PolytechGameInstance.h"

UPolytechGameInstance::UPolytechGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void UPolytechGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updatede: %d"), TotalScore);
}