// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//변수 세팅보다 생성자가 우선 호출
	mMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	/*
	if (FX_DirectPropertyReference)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GWorld, FX_DirectPropertyReference, this->GetActorTransform());
	}
	*/
	
	
	if (widget_class)
	{
		//UBlueprint* obj = LoadObject<UBlueprint>(nullptr, TEXT("WidgetBlueprint'/Game/BP/test.test'"));
		//UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), widget_class);
		//widget->AddToViewport();
		
		widget1 = CreateWidget<UUserWidget>(GetWorld(), widget_class);
		widget1->AddToViewport();
		/*
		UUserWidget* ui = CreateWidget<UUserWidget>(GetWorld(), widget_softClass.LoadSynchronous());
		ui->AddToViewport();
		*/
		//UserInterface = CreateWidget<UMyUserWidget>(this, UMyUserWidget::StaticClass());
	}
	/*
	if (widget_softClass)
	{
		UUserWidget* ui = CreateWidget<UUserWidget>(GetWorld(), widget_softClass.LoadSynchronous());
		ui->AddToViewport();
	}
	*/
	if (widget_softClass)
	{
		auto& assetLoader = UAssetManager::GetStreamableManager();
		assetLoader.RequestAsyncLoad(widget_softClass.ToStringReference(), FStreamableDelegate::CreateUObject(this, &ATestActor::OnAsset));

		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Blue, widget_softClass.ToStringReference().ToString());
	}
	
	if (SoftMesh)
	{
		UStaticMesh* mesh = SoftMesh.LoadSynchronous();
		UStaticMeshComponent* NewMesh = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), FName("SoftMesh"));
		NewMesh->AttachTo(RootComponent, NAME_None, EAttachLocation::SnapToTarget);
		NewMesh->SetRelativeLocation(FVector(0, 0, 200));
		NewMesh->SetStaticMesh(mesh);
		NewMesh->RegisterComponent();
	}

	if (SoftMesh)
	{
		auto& assetLoader = UAssetManager::GetStreamableManager();
		assetLoader.RequestAsyncLoad(SoftMesh.ToStringReference(), FStreamableDelegate::CreateUObject(this, &ATestActor::OnAsset2));
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Blue, SoftMesh.ToStringReference().ToString());
	}
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor::OnConstruction(const FTransform& Transform)
{
	if (BashMesh)
	{
		mMesh->SetStaticMesh(BashMesh);
	}
}

void ATestActor::OnAsset()
{
	//Get() 소프트 포인트 역참조
	//@return nullptr 이 객체가 없거나 소프트 포인터가 null이면 유효한 UCLASS pointer
	UUserWidget* ui = CreateWidget<UUserWidget>(GetWorld(), widget_softClass.LoadSynchronous());
	ui->AddToViewport();
}

void ATestActor::OnAsset2() 
{
	UStaticMesh* mesh = SoftMesh.Get();
	UStaticMeshComponent* NewMesh = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), FName("SoftMesh2"));
	NewMesh->AttachTo(RootComponent, NAME_None, EAttachLocation::SnapToTarget);
	NewMesh->SetRelativeLocation(FVector(0, 0, 400));
	NewMesh->SetStaticMesh(mesh);
	NewMesh->RegisterComponent();
}

