// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shared.h"
#include "GameFramework/Actor.h"
#include "WLActor.generated.h"




UCLASS()
class WELEVEL_TEST_API AWLActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWLActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tags")
	void AddTag(FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Tags")
	const FGameplayTagContainer& GetTags() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Tags")
	FGameplayTagContainer GameTags;
	

};
