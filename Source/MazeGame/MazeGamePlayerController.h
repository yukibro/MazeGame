// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MazeGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API AMazeGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class URestartWidget> BP_RestartWidget;

	void ShowRestartWidget();
	void HideRestartWidget();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UExitWidget> BP_ExitWidget;

	void ShowExitWidget();
	void HideExitWidget();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UHUDWidget> BP_HUDWidget;

	void UpdateHealthPercent(float HelathPercent);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		class URestartWidget* RestartWidget;
	
	UPROPERTY()
		class UExitWidget* ExitWidget;

	UPROPERTY()
		class UHUDWidget* HUDWidget;
};
