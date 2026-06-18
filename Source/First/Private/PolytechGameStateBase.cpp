#include "PolytechGameStateBase.h"

APolytechGameStateBase::APolytechGameStateBase()
{
	Score = 0;
}

int32 APolytechGameStateBase::GetScore() const
{
	return Score;
}

void APolytechGameStateBase::AddScore(int32 Amount)
{
	Score += Amount;
	if (Score > 50) {
		UE_LOG(LogTemp, Display, TEXT("CLEAR"));
	}
}
