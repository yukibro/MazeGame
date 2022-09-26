// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeProjectile.h"
#include "Components/SphereComponent.h"
#include "MazeGameCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMazeProjectile::AMazeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereComponent->SetSphereRadius(15.f);
	SphereComponent->SetCollisionProfileName(FName("Maze"));
	SphereComponent->SetSimulatePhysics(true);
	SphereComponent->SetNotifyRigidBodyCollision(true);
	SphereComponent->OnComponentHit.AddDynamic(this, &AMazeProjectile::OnHit);

	RootComponent = SphereComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = 1000.f;
}

// Called when the game starts or when spawned
void AMazeProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.f);
}

// Called every frame
void AMazeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (BounceSound != nullptr && NormalImpulse.Size() > 600.0f) {
		UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation(), 1.0f, FMath::RandRange(0.7f, 1.3f), 0.0f, BounceSoundAttenuation);
	}
	AMazeGameCharacter* Player = Cast<AMazeGameCharacter>(OtherActor);
	if (Player != nullptr) {
		UHealthComponent* HealthComponent = Player->FindComponentByClass<UHealthComponent>();
		if (HealthComponent != nullptr) {
			HealthComponent->LoseHealth(Damage);
		}
		if (HitParticles != nullptr) {
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticles, GetActorTransform());
		}
		if (HitSound != nullptr) {
			UGameplayStatics::PlaySound2D(this, HitSound);
		}
		Destroy();
	}
}