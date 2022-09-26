// Fill out your copyright notice in the Description page of Project Settings.

#include "VictoryPoint.h"
#include "Components/BoxComponent.h"
#include "Components/Button.h"
#include "MazeGameCharacter.h"
#include "MazeGamePlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

// Sets default values
AVictoryPoint::AVictoryPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(FVector(60.0f, 60.0f, 60.0f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AVictoryPoint::OnBeginOverlap);


}

// Called when the game starts or when spawned
void AVictoryPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVictoryPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVictoryPoint::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (Cast<AMazeGameCharacter>(OtherActor)) {
		Cast<AMazeGamePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->ShowExitWidget();
		//UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
	}
}