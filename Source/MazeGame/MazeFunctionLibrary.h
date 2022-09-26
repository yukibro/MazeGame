// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MazeFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API UMazeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static bool CanSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgnoreActors = TArray<const AActor*>());
};
