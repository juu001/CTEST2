// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObject.h"
#include "MyActor2.generated.h"

/*
* 열거형 : 기본적으로 저렴한 비용의 데이터 유형을 사용하여 사람이 읽을 수 있는 긴 이름으로 일련의 관련 유형을 정의 할 수 있는 기능입니다.
*/

UENUM(BlueprintType)
enum class ETestEnum : uint8 //0~255
{
	Dance UMETA(DisplayName = "Dance"),
	Rain UMETA(DisplayName = "Rain"),
	Song UMETA(DisplayName = "Song")
};

USTRUCT(BlueprintType)
struct FTestStruct
{
	GENERATED_BODY()
public:
	//구조체 안에서 변수 사용시, UPROPERTY()가 아닌 변수는 복제X

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")
	int32 NumPetals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")
	FVector Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")
	FVector Scale3D;
};

UCLASS()
class CTEST2_API AMyActor2 : public AActor, public IMyObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	ETestEnum TestEnum;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TestInterFace")
	void Call_InerFace();
	virtual void Call_InerFace_Implementation() override;

	
};
