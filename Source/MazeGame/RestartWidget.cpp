// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "MazeGamePlayerController.h"

void URestartWidget::OnRestartClicked() {
	AMazeGamePlayerController* PlayerController = Cast<AMazeGamePlayerController>(GetOwningPlayer());
	if (PlayerController != nullptr) {
		PlayerController->HideRestartWidget();
	}

	UGameplayStatics::OpenLevel(this, TEXT("Level1"));
}

void URestartWidget::OnExitClicked() {
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void URestartWidget::NativeOnInitialized() {
	Super::NativeOnInitialized();

	if (RestartButton != nullptr) {
		RestartButton->OnClicked.AddDynamic(this, &URestartWidget::OnRestartClicked);
	}

	if (ExitButton != nullptr) {
		ExitButton->OnClicked.AddDynamic(this, &URestartWidget::OnExitClicked);
	}
}
