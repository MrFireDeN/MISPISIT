// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIObserver.h"
#include "Blueprint/UserWidget.h"
#include "MITimeObserverWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class MISPISIT_API UMITimeObserverWidget : public UUserWidget, public IMIObserver
{
	GENERATED_BODY()

public:
	virtual void OnTimeUpdate_Implementation(int32 NewTime) override;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimeText;

private:
	static void FormatTime(int32 TotalSeconds, FString& OutString);
};
