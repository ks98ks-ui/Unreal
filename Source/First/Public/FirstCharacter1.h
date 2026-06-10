#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPlayerController1.h"
#include "FirstCharacter1.generated.h"


//전방선언부터 시작
class USpringArmComponent; //스프링암 관련 클래스의 헤더
class UCameraComponent;  // 카메라 관련 클래스 전방선언
// Enhanced Input에서 액션값을 받을 때 사용하는 구조체
struct FInputActionValue;

UCLASS()
class FIRST_API AFirstCharacter1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstCharacter1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// 스프링암 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") //Unreal의 reflection system
	USpringArmComponent* SpringArmComp;
	
	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;


	// IA_Mobe 와 IA_Jump 등을 처리할 함수의 원형
	//Enhanced Input에서의 액션 값은 FInputActionValue 로 전환
	UFUNCTION()
	void Move(const FInputActionValue& value);

	UFUNCTION()
	void StartJump(const FInputActionValue& value);

	UFUNCTION()
	void StopJump(const FInputActionValue& value);

	UFUNCTION()
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void StartSprint(const FInputActionValue& value);

	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	//이동속력 관련 프로퍼티
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float NomalSpeed; // 기본속력

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintSpeedMultiplier; //기본속력대비 몇배 빠르게 움직이도록 설정

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	float SprintSpeed; //실제 속도

};
