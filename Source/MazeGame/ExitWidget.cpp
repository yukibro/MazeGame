// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UExitWidget::OnExitClicked() {
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UExitWidget::NativeOnInitialized() {
	Super::NativeOnInitialized();

	if (ExitButton != nullptr) {
		ExitButton->OnClicked.AddDynamic(this, &UExitWidget::OnExitClicked);
	}
}