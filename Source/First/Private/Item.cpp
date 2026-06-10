#include "Item.h"

// Sets default values
AItem::AItem()
{
	

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// StaticMesh Component 생성 및 컴포넌트 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);



	//StaticMesh 할당
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded()) 
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder <UMaterial> MaterialAsset(TEXT("/Game/Resource/Materials/M_Metal_Gold.M_Metal_Gold")); 
	if(MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	UE_LOG(LogTemp, Warning, TEXT("#1 Item Construct!"));

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{

	Super::BeginPlay();

	//BeginPlay 호출 시점을 로그로 확인
	UE_LOG(LogTemp, Warning, TEXT("#2 Item Spawaned!"));
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("#3 Item Tick!"));
	PrimaryActorTick.bCanEverTick = false;


}

