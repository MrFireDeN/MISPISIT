// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/Observer/MITimeObserverWidget.h"

#include "Components/TextBlock.h"
#include "Game/DesignPatterns/Behavioral/Observer/MITimeServerSubsystem.h"

void UMITimeObserverWidget::OnTimeUpdate_Implementation(int32 NewTime)
{
	FString Formatted;
	FormatTime(NewTime, Formatted);

	if (TimeText)
	{
		TimeText->SetText(FText::FromString(Formatted));
	}

	UE_LOG(LogTemp, Display, TEXT("[%s] Time: %s"), *GetNameSafe(this), *Formatted);
}

void UMITimeObserverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Subscribe(this);
	}
}

void UMITimeObserverWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (UMITimeServerSubsystem* TimeServer = GetWorld()->GetSubsystem<UMITimeServerSubsystem>())
	{
		TimeServer->Unsubscribe(this);
	}
}

void UMITimeObserverWidget::FormatTime(const int32 TotalSeconds, FString& OutString)
{
	int32 Hours = TotalSeconds / 3600;
	int32 Minutes = (TotalSeconds / 60) % 60;
	int32 Seconds = TotalSeconds % 60;

	OutString = FString::Printf(TEXT("%02d:%02d:%02d"), Hours, Minutes, Seconds);
}
