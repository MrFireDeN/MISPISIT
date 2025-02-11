// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractebleHelper.h"

void UInteractebleHelper::CallOnPrimaryAction(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnPrimaryAction();
	}
}

void UInteractebleHelper::CallOnSecondaryAction(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnSecondaryAction();
	}
}

void UInteractebleHelper::CallOnNumericAction(AActor* Target, const int Digit)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnNumericAction(Digit);
	}
}

void UInteractebleHelper::CallOnCustomKeyAction(AActor* Target, const FKey Key)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnCustomKeyAction(Key);
	}
}
