// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WLActor.h"

// Sets default values
AWLActor::AWLActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWLActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWLActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWLActor::AddTag(FGameplayTag Tag)
{
	if(GameTags.HasTag(Tag)) return;
	
	GameTags.AddTag(Tag);
}

const FGameplayTagContainer& AWLActor::GetTags() const
{
	return GameTags;
}

