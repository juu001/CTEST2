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

	// Ŭ���� ���´� �Ϲ� ������ ������ ��ü ����Ʈ ������ ��� �ִ�.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	UUserWidget* widget1;
	
	/* TSubclassOf<T> Ŭ���� ������ ���� ���۷���
	* �� ���������� type�������� ���� ����ϴ� ��찡 ����
	* �� ������ ������ Ŭ���� ������ T�� ����� Class�� ��� �ǹ̸� ��Ȯ�� �� ��, ����ϴ� ������ ��
	* 
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	TSubclassOf<UUserWidget> widget_class;

	/* SoftClassPtr<T> ���� ���۷��� ���� �ε�
	* �� �״�� Class�� ����Ʈ �����Ͷ�� ������, �ش� ���� ����Ű�� �����ʹ� ���� ������ ���ø����� �������� ��
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "userwidget")
	TSoftClassPtr<UUserWidget> widget_softClass;
};
