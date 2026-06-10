#include "FirstPlayerController1.h"
#include "EnhancedInputSubsystems.h"

AFirstPlayerController1::AFirstPlayerController1()
	:InputMappingContext(nullptr), 
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr)
{
}

void AFirstPlayerController1::BeginPlay()
{
	Super::BeginPlay();

	//현재 PlayerController에 연결된 Local Player 객체를 가져오기
	//만약 LocalPlayer 가있으면 현재 PlayerController 가 가지고 있는 IMC를 사용
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// Local Player 에서 EnhancedInputLocalPayerSubsystem을 획득
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				// Subsystem 을 통해 우리가 할당한 IMC를 활성화
				//우선순위는 Single play이므로 0(가장높은 우선순위) 세팅
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}

}
