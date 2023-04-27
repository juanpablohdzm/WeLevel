// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNodes/WLAsyncTagListener.h"

#include "Actors/WLActor.h"

UWLAsyncTagListener* UWLAsyncTagListener::AsyncDetectTagChange(AActor* Owner, AWLActor* Actor)
{
	UWLAsyncTagListener* newAsyncDetectTagNode = NewObject<UWLAsyncTagListener>();
	newAsyncDetectTagNode->Target = Actor;
	newAsyncDetectTagNode->Owner = Owner;
	return newAsyncDetectTagNode;
}

void UWLAsyncTagListener::Activate()
{
	Super::Activate();

	if(!Target.IsValid() || !Owner.IsValid()) return;

	OldTags = Target->GetTags();
	FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UWLAsyncTagListener::AsyncDetectTagChange_Internal),0.f);
}

bool UWLAsyncTagListener::AsyncDetectTagChange_Internal(float DeltaTime)
{
	if(!Target.IsValid() || !Owner.IsValid())
	{
		SetReadyToDestroy();
		return false;
	}
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask,[&]()
	{
		FGameplayTagContainer NewTags = Target->GetTags();
		if (NewTags != OldTags)
		{
			OldTags = NewTags;
			AsyncTask(ENamedThreads::GameThread, [&]()
			{
				OnTagChanged.Broadcast();
			});
		}
	});
	
	return Target.IsValid() && Owner.IsValid();
}
