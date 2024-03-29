// Fill out your copyright notice in the Description page of Project Settings.

#include "TestUI.h"
#include "Button.h"
#include "CanvasPanelSlot.h"

void UTestUI::NativeConstruct()
{
	Super::NativeConstruct();
	if (ButtonTest)
	{
		ButtonTest->OnClicked.AddDynamic(this, &UTestUI::OnButtonClicked);
		//UCanvasPanelSlot* PanelSlot = Cast<UCanvasPanelSlot>(ButtonTest->Slot);
		//if (PanelSlot)
		//{
		//	PanelSlot->SetSize({ 200,200 });
		//}
	}

	ButtonBP = Cast<UButton>(GetWidgetFromName("ButtonBP"));
	if (ButtonBP)
	{
		ButtonBP->OnClicked.AddDynamic(this, &UTestUI::OnBPButtonClicked);
	}
}

void UTestUI::NativeDestruct()
{
	Super::NativeDestruct();
	if (ButtonTest)
	{
		ButtonTest->OnClicked.RemoveAll(this);
	}
	if (ButtonBP)
	{
		ButtonBP->OnClicked.RemoveAll(this);
	}
}

void UTestUI::OnButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Button is clicked."));
}

void UTestUI::OnBPButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("BP button is clicked."));
}
