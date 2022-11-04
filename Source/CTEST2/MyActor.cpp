// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Containers/Array.h"
#include "Kismet/KismetStringLibrary.h"
//#include "MyObject.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StrArr = { "hello", "brave","world", "of", "tommorow", "!"};
	

	/*
	for (auto& Str : StrArr) 
	{
		Temp += Str;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Temp);
	}
	*/

	/* ?????
	for (int32 Index = 0; Index != StrArr.Num(); ++Index)
	{
		if (Index != 1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, StrArr[Index]);
		}
	}
	*/

	/*
	for (FString Str : StrArr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, Str);
	}
	*/

	//Temp = UKismetStringLibrary::JoinStringArray(StrArr); // -> 배열에 있는 모든 원소들의 결합
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Temp);
	/*
	TArray<TArray<FString>>StrArr2;
	StrArr2.Add(StrArr);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, StrArr2[0][4]);

	StrArr2.Add({TEXT("0"),TEXT("1")});
	StrArr2[1].Add(TEXT("2"));
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, StrArr2[1][2]);
	*/

	/*
	//text 조합공부
	//UE_LOG(LogTemp, Warning, TEXT(""));
	int32 inVar = 5;
	float flVar = 3.6f;
	FString StrVar = TEXT("test");
	UE_LOG(LogTemp, Warning, TEXT("some warning message, %d %f %s"), inVar, flVar,&StrVar);

	//text조합 use fstring
	FString name = "Tim";
	int32 mana = 450;
	FString string = FString::Printf(TEXT("name = %s, mana = %d"), *name, mana);
	UE_LOG(LogTemp, Warning, TEXT("your string1 : %s"),*string);

	//format
	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(mana));
	FString string2 = FString::Format(TEXT("name = {0} mana = {1}"), args);
	UE_LOG(LogTemp, Warning, TEXT("your string2 : %s"), *string2);

	//FStringFormatArg : FString::Format에 사용되는 구조체
	//FString::Format
	//지정된 인수를 사용하여 지정된 문자열의 형식을 지정합니다.
	//문자열에 넣은 변수의 유형을 추론하는데 도움이 됩니다.
	*/

	/*
	FString test = TEXT("1234 test");
	// 문자열 비교
	if (test.Equals(TEXT("test")))
	{
		UE_LOG(LogClass, Error, TEXT("true"));
	}
	else
	{
		UE_LOG(LogClass, Error, TEXT("false"));
	}
	//검색
	if (test.Find(TEXT("test")))
	{
		UE_LOG(LogClass, Error, TEXT("true"));
	}
	else
	{
		UE_LOG(LogClass, Error, TEXT("false"));
	}
	//자르기
	FString testRight;
	test.Split(" ", nullptr, &testRight);
	*/

	//GetClass와 StaticClass
	/*
	FindFProperty<FStrProperty>
	UE_LOG(LogClass, Error, TEXT("FStrProperty : %s"),*string);
	*/
	FStrProperty* FindText = FindFProperty<FStrProperty>(this->GetClass(), TEXT("TEST"));
	UE_LOG(LogClass, Error, TEXT("FStrProperty : %s"), FindText);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FStrProperty* FindText = FindFProperty<FStrProperty>(this->GetClass(), TEXT("TEST"));
	if (FindText)
	{
		FString string = *FindText->GetPropertyValuePtr_InContainer(this);
		UE_LOG(LogClass, Error, TEXT("FStrProperty : %s"), *string);
	}
	//if(this->GetClass() == AMyActor::StaticClass())
	if (this->GetClass() == AMyActor::StaticClass())
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("same"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("no"));
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyActor::Call_InerFace_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("1hi"));
}


