// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "TestActor.generated.h"

UCLASS()
class CTEST2_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Particle")
	UParticleSystem* FX_DirectPropertyReference;

	// 클래스 형태는 일반 유형은 생성된 객체 포인트 정보를 담고 있다.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	UUserWidget* widget1;
	
	/* TSubclassOf<T> 클래스 형태의 직접 레퍼런싱
	* 이 데이텨형은 type안정성을 위해 사용하는 경우가 많다
	* 즉 값으로 들어오는 클래스 정보는 T를 상속한 Class다 라는 의미를 명확히 할 때, 사용하는 데이터 형
	* 
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	TSubclassOf<UUserWidget> widget_class;

	/* SoftClassPtr<T> 간접 레퍼런싱 수동 로딩
	* 말 그대로 Class의 소프트 포인터라는 뜻으로, 해당 값이 가리키는 데이터는 직접 지정한 템플릿형의 데이터일 것
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	TSoftClassPtr<UUserWidget> widget_softClass;
};
