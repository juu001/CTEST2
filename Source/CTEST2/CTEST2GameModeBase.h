// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CTEST2GameModeBase.generated.h"


/*
���ø��� c++ ���α׷��� ����� �� �������, �Լ��� Ŭ������ ���ʸ� ���� �����ϵ��� ���� �ݴϴ�.
�Լ��� Ŭ������ ���������� �ٽ� �ۼ����� �ʰ� ���� �ٸ� ������ �ڷ������� ������ �� �ְ� �մϴ�.

�⺻��
template<typename ~~>
FORCEINLINE void YourFuntion
{
	//����
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
