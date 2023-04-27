// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "WLAsyncTagListener.generated.h"

class AWLActor;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate);
/**
 * 
 */
UCLASS()
class WELEVEL_TEST_API UWLAsyncTagListener : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UWLAsyncTagListener* AsyncDetectTagChange(AActor* Owner,AWLActor* Actor);
	
	UPROPERTY(BlueprintAssignable)
	FDelegate OnTagChanged;


	virtual void Activate() override;

protected:
	TWeakObjectPtr<AWLActor> Target;
	TWeakObjectPtr<AActor> Owner;

private:

	bool AsyncDetectTagChange_Internal(float DeltaTime);
	FGameplayTagContainer OldTags;
	
};
