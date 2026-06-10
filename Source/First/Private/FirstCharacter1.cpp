#include "FirstCharacter1.h"
// 카메라 및 스프링암 (전방선언 했었던 헤더 include
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
//Input 구현 위해 아래 두 헤더 추가
#include "EnhancedInputComponent.h"
#include "FirstPlayerController1.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFirstCharacter1::AFirstCharacter1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// #1스프링암 생성
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//Root Component 에 스프링 암을 부착
	SpringArmComp->SetupAttachment(RootComponent);
	//캐릭터와 카메라 사이의 거리를 사전설정
	SpringArmComp->TargetArmLength = 300.0f;
	//컨트롤러의 회전에 따라 스프링암도 이동하도록 설정
	SpringArmComp->bUsePawnControlRotation = true;
	
	//#2 카메라 컴포넌트 생성
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//스프링암의 소켓 위치에 카메라를 부착
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	//카메라는 스프링 암의 회전을 따르므로, PawnControlRotation 꺼두기
	CameraComp->bUsePawnControlRotation = false;

	//Sprint 관련
	NomalSpeed = 600.f;
	SprintSpeedMultiplier = 1.5f;
	SprintSpeed = NomalSpeed * SprintSpeedMultiplier;

	GetCharacterMovement()->MaxWalkSpeed = NomalSpeed;

}

// Called when the game starts or when spawned
void AFirstCharacter1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstCharacter1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstCharacter1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Enhanced Input Component 캐스팅
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// IA 를 가져오기 위해서 현재 이 캐릭터를 control중인 FirstPlayerController 캐스팅
		if (AFirstPlayerController1* PlayerController = Cast<AFirstPlayerController1>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				//액션 키를 누르고 있는 동안 특정 기능 실행
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AFirstCharacter1::Move
				);
			}

			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&AFirstCharacter1::StartJump
				);
			}

			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&AFirstCharacter1::StopJump
				);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AFirstCharacter1::Look
				);
			}

			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&AFirstCharacter1::StartSprint
				);
			}

			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&AFirstCharacter1::StopSprint
				);
			}
		}
	}
}

void AFirstCharacter1::Move(const FInputActionValue& value)
{
	//컨트롤러가 있어야 방향계산이 가능하므로 컨트롤러가 없는경우 return
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();
	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		//캐릭터가 바라보는 방향으로 X축 이동
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		//캐릭터의 오른쪽 방향으로 Y축이동
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void AFirstCharacter1::Look(const FInputActionValue& value)
{
	//마우스의 x,y의 움직임을 2D축으로 가져오기
	FVector2D LookInput = value.Get<FVector2D>();

	//Yaw, Pitch 축만 활용하며 Rotation(카메라의 고개만 끄덕or 도리도리 거리는 방식으로 디자인해야 플에이어가 시야에서 벗어나지않음) 
	//좌우 회전
	AddControllerYawInput(LookInput.X); //카메라의 Yaw축 (수평회전)을 중심으로 Rotation값 변경

	//상하 회전
	AddControllerPitchInput(LookInput.Y); //카메라의 Yaw축(수wlr회전)을 중심으로 Rotation값 변경

	//실제 어느 방향으로 얼마나 회전할지는 프로젝트 세팅에서 수정가능

}

void AFirstCharacter1::StartJump(const FInputActionValue& value)
{
	//Jump함수는 Character 클래스 내장함수 이므로 구현할 필요없이 가져다 사용하면 됨
	if (value.Get<bool>())
	{
		Jump();
	}
}

void AFirstCharacter1::StopJump(const FInputActionValue& value)
{
	//StopJumping 함수도 기본함
	if (value.Get<bool>())
	{
		StopJumping();
	}
}

void AFirstCharacter1::StartSprint(const FInputActionValue& value)
{
	//left shift키를 누르면 이 함수가 호출 됨
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}

void AFirstCharacter1::StopSprint(const FInputActionValue& value)
{
	//left shift키를 떼면 이 함수가 호출됨
	//평상시 속도로 복귀
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = NomalSpeed;
	}
}

