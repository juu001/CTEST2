// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 인터페이스
 * 인터페이스를 통해 다른 객체가 공통 기능을 공유할 수 있지만, 필요한 경우 객체가 해당 기능을 다르게 처리 할 수 있다.
 */
UINTERFACE(BlueprintType)
class CTEST2_API UMyObject : public UInterface
{
	GENERATED_BODY()
	
};

class CTEST2_API IMyObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TestInterFace")
	void Call_InerFace();
	/*
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TestInterFace")
	void Call_InerFace();
	*/
};
