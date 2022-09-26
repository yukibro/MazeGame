// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Level1EnemyCharacter.generated.h"

UCLASS()
class MAZEGAME_API ALevel1EnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALevel1EnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Change the rotation of the character to face the given actor

	// Can we see the given actor

	bool bCanseePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.0f;
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