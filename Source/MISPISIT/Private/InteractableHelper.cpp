

// InteractableHelper.cpp

#include "InteractableHelper.h"

void UInteractableHelper::CallOnAttach(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnAttach();
	}
}

void UInteractableHelper::CallOnDetach(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnDetach();
	}
}

void UInteractableHelper::CallOnTouch(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnTouch();
	}
}

/**
 * Calls the OnPrimaryAction function on the target actor if it implements the ICPP_Interactable interface.
 * 
 * @param Target The actor to interact with. Must implement ICPP_Interactable.
 */
void UInteractableHelper::CallOnPrimaryAction(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnPrimaryAction();
	}
}

/**
 * Calls the OnSecondaryAction function on the target actor if it implements the ICPP_Interactable interface.
 * 
 * @param Target The actor to interact with. Must implement ICPP_Interactable.
 */
void UInteractableHelper::CallOnSecondaryAction(AActor* Target)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnSecondaryAction();
	}
}

/**
 * Calls the OnNumericAction function on the target actor if it implements the ICPP_Interactable interface.
 * 
 * @param Target The actor to interact with. Must implement ICPP_Interactable.
 * @param Digit The numeric value associated with the action.
 */
void UInteractableHelper::CallOnNumericAction(AActor* Target, const int Digit)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnNumericAction(Digit);
	}
}

/**
 * Calls the OnCustomKeyAction function on the target actor if it implements the ICPP_Interactable interface.
 * 
 * @param Target The actor to interact with. Must implement ICPP_Interactable.
 * @param Key The custom key associated with the action.
 */
void UInteractableHelper::CallOnCustomKeyAction(AActor* Target, const FKey Key)
{
	if (ICPP_Interactable* Interactable = Cast<ICPP_Interactable>(Target))
	{
		Interactable->OnCustomKeyAction(Key);
	}
}