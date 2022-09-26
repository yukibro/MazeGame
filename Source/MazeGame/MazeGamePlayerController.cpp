// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGamePlayerController.h"
#include "RestartWidget.h"
#include "ExitWidget.h"
#include "HUDWidget.h"

void AMazeGamePlayerController::BeginPlay() {
	Super::BeginPlay();

	if (BP_HUDWidget != nullptr) {
		HUDWidget = CreateWidget<UHUDWidget>(this, BP_HUDWidget);
		HUDWidget->AddToViewport();
	}
}

void AMazeGamePlayerController::UpdateHealthPercent(float HealthPercent) {
	if (HUDWidget != nullptr) {
		HUDWidget->UpdateHealthPercent(HealthPercent);
	}
}

void AMazeGamePlayerController::ShowRestartWidget() {
	if (BP_RestartWidget != nullptr) {
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		RestartWidget = CreateWidget<URestartWidget>(this, BP_RestartWidget);
		RestartWidget->AddToViewport();
	}
}

void AMazeGamePlayerController::HideRestartWidget() {
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AMazeGamePlayerController::ShowExitWidget() {
	if (BP_ExitWidget != nullptr) {
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		ExitWidget = CreateWidget<UExitWidget>(this, BP_ExitWidget);
		ExitWidget->AddToViewport();
	}
}

void AMazeGamePlayerController::HideExitWidget() {
	ExitWidget->RemoveFromParent();
	ExitWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
