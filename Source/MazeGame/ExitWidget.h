// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExitWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API UExitWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UFUNCTION()
		void OnExitClicked();

public:

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;
	
	virtual void NativeOnInitialized() override;
};
