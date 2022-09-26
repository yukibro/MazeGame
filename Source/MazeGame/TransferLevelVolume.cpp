// Fill out your copyright notice in the Description page of Project Settings.


#include "TransferLevelVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/Classes/Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATransferLevelVolume::ATransferLevelVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TransferVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TransferVolume"));
	
	TransferVolume->SetBoxExtent(FVector(30.0f, 30.0f, 30.0f));
	TransferVolume->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	TransferVolume->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	
	RootComponent = TransferVolume;
}

// Called when the game starts or when spawned
void ATransferLevelVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATransferLevelVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATransferLevelVolume::NotifyActorBeginOverlap(AActor* OtherActor) {
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn != nullptr) {
		UGameplayStatics::OpenLevel(this, TransferLevelName);
	}
	
}