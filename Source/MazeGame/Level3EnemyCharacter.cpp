// Fill out your copyright notice in the Description page of Project Settings.


#include "Level3EnemyCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "MazeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "LookAtActorComponent.h"

// Sets default values
ALevel3EnemyCharacter::ALevel3EnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LookAtActorComponent = CreateDefaultSubobject<ULookAtActorComponent>(TEXT("Look At Actor Component"));
	LookAtActorComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALevel3EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	LookAtActorComponent->SetTarget(PlayerCharacter);
	
}

// Called every frame
void ALevel3EnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bCanseePlayer = LookAtActorComponent->CanSeeTarget();

	if (bCanseePlayer != bPreviousCanSeePlayer) {
		if (bCanseePlayer) {
			GetWorldTimerManager().SetTimer(ThrowTimerHandle, this, &ALevel3EnemyCharacter::ThrowBall, ThrowingInterval, true, ThrowingDelay);
		}
		else {
			GetWorldTimerManager().ClearTimer(ThrowTimerHandle);
		}
	}
	bPreviousCanSeePlayer = bCanseePlayer;
}

void ALevel3EnemyCharacter::ThrowBall() {
	if (MazeClass == nullptr) {
		return;
	}

	FVector ForwardVector = GetActorForwardVector();
	float SpawnDistance = 40.f;
	FVector SpawnLocation = GetActorLocation() + (ForwardVector * SpawnDistance);

	FTransform SpawnTransform(GetActorRotation(), SpawnLocation);
	AMazeProjectile* Projectile = GetWorld()->SpawnActorDeferred<AMazeProjectile>(MazeClass, SpawnTransform);

	Projectile->GetProjectileMovementComponent()->InitialSpeed = 1300.f;
	Projectile->FinishSpawning(SpawnTransform);
}
