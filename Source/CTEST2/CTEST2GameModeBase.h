// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CTEST2GameModeBase.generated.h"


/*
템플릿은 c++ 프로그래밍 언어의 한 기능으로, 함수와 클래스가 제너릭 형과 동작하도록 도와 줍니다.
함수나 클래스가 개별적으로 다시 작성하지 않고도 각기 다른 수많은 자료형에서 동작할 수 있게 합니다.

기본형
template<typename ~~>
FORCEINLINE void YourFuntion
{
	//본문
}
*/

template<typename MyObjType>
static FORCEINLINE MyObjType* SpawnActorType(UWorld* TheWorld)
{
	if (!TheWorld) { return 0; }
	FVector Loc = FVector(0);
	FRotator Rot = FRotator(0);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnInfo.bDeferConstruction = false;
	return TheWorld->SpawnActor<MyObjType>(MyObjType::StaticClass(), Loc, Rot, SpawnInfo);
}

/**
 * 
 */
UCLASS()
class CTEST2_API ACTEST2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(Exec, Category = "Console Command")
	void TestLog();

	UFUNCTION(Exec, Category = "Console Command")
	void PrintString(FString String);


};
