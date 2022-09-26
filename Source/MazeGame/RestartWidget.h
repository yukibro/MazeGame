// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RestartWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API URestartWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	/*UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FName FirstLevel;*/

protected:
	UFUNCTION()
		void OnRestartClicked();

	UFUNCTION()
		void OnExitClicked();

public:
	UPROPERTY(meta = (BindWidget))
	class UButton* RestartButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;

	virtual void NativeOnInitialized() override;
};
