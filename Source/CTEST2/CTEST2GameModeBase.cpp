// Copyright Epic Games, Inc. All Rights Reserved.


#include "CTEST2GameModeBase.h"
#include "EngineUtils.h"
#include "MyObject.h"
#include "MyActor.h"


void ACTEST2GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	/*
	//모든 액터 찾기 인터페이스 함수 호출
	//방식1
	AActor* Character = GetOwner();
	IInterface* Interface = Cast<IInterface>(Character);
	if (Interface != nullptr)
	{
		Interface->SetOnAttack();
	}
	//방식2
	if (Character->GetClass()->ImplementsInterface(UInterface::StaticClass()))
	{
		//직접 함수를 호출하지 말고 'Excute_'접두어를 사용하십시오.
		//Excute_ReactToHighNoon 및 Excute_ReactToMidnight가 컴파일시 생성
		//이러한 함수가 표시되기 전에 컴파일해야 할 수도
		IInterface_PlayerCharacter::Excute_SetOnAttack(Character);
	}
	*/
	for (TActorIterator<AActor> actor(GWorld); actor; ++actor)
	{
		//방식1
		IMyObject* test = Cast<IMyObject>(*actor);
		if (test)
		{
			test->Execute_Call_InerFace(*actor);
		}
		//방식2
		if (actor->GetClass()->ImplementsInterface(UMyObject::StaticClass()))
		{
			IMyObject::Execute_Call_InerFace(*actor);
		}
	}
	
	SpawnActorType<AMyActor>(GWorld);

}

void ACTEST2GameModeBase::TestLog()
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Silver, TEXT("hello"));

}

void ACTEST2GameModeBase::PrintString(FString String)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Silver, String);
}
