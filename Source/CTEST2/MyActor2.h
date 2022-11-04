// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObject.h"
#include "MyActor2.generated.h"

/*
* ������ : �⺻������ ������ ����� ������ ������ ����Ͽ� ����� ���� �� �ִ� �� �̸����� �Ϸ��� ���� ������ ���� �� �� �ִ� ����Դϴ�.
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
	//����ü �ȿ��� ���� ����, UPROPERTY()�� �ƴ� ������ ����X

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
