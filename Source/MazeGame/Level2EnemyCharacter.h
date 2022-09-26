// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Level2EnemyCharacter.generated.h"

UCLASS()
class MAZEGAME_API ALevel2EnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALevel2EnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bCanseePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 3.0f;
	float ThrowingDelay = 0.7f;

	void ThrowBall();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Maze)
		TSubclassOf<class AMazeProjectile> MazeClass;

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
		class ULookAtActorComponent* LookAtActorComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
