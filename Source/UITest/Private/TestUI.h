// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUI.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class UTestUI : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(Meta = (BindWidget))
	class UButton* ButtonTest;

	class UButton* ButtonBP;
	
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnButtonClicked();

	UFUNCTION()
	void OnBPButtonClicked();
};
