// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	if (TestEnum == ETestEnum::Dance)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("Dance"));
	}
	else if (TestEnum == ETestEnum::Rain)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("Rain"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("Song"));
	}
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor2::Call_InerFace_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Black, TEXT("2hi"));
}

