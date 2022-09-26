// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeProjectile.generated.h"

UCLASS()
class MAZEGAME_API AMazeProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Damage)
		float Damage = 34.0f;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* BounceSound;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundAttenuation* BounceSoundAttenuation;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = Particles)
		class UParticleSystem* HitParticles;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Maze, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* SphereComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Maze, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FORCEINLINE UProjectileMovementComponent* GetProjectileMovementComponent() const {
		return ProjectileMovement;
	}
};
