// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransferLevelVolume.generated.h"

UCLASS()
class MAZEGAME_API ATransferLevelVolume : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ATransferLevelVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY()
		class UBoxComponent* TransferVolume;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FName TransferLevelName;

};
