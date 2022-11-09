// Copyright Epic Games, Inc. All Rights Reserved.


#include "CTEST2GameModeBase.h"
#include "EngineUtils.h"
#include "MyObject.h"
#include "MyActor.h"


void ACTEST2GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	/*
	//��� ���� ã�� �������̽� �Լ� ȣ��
	//���1
	AActor* Character = GetOwner();
	IInterface* Interface = Cast<IInterface>(Character);
	if (Interface != nullptr)
	{
		Interface->SetOnAttack();
	}
	//���2
	if (Character->GetClass()->ImplementsInterface(UInterface::StaticClass()))
	{
		//���� �Լ��� ȣ������ ���� 'Excute_'���ξ ����Ͻʽÿ�.
		//Excute_ReactToHighNoon �� Excute_ReactToMidnight�� �����Ͻ� ����
		//�̷��� �Լ��� ǥ�õǱ� ���� �������ؾ� �� ����
		IInterface_PlayerCharacter::Excute_SetOnAttack(Character);
	}
	*/
	for (TActorIterator<AActor> actor(GWorld); actor; ++actor)
	{
		//���1
		IMyObject* test = Cast<IMyObject>(*actor);
		if (test)
		{
			test->Execute_Call_InerFace(*actor);
		}
		//���2
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
