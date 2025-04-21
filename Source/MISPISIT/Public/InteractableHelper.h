// CPP_InteractableHelper.h

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_Interactable.h"
#include "InteractableHelper.generated.h"

/**
 * UInteractableHelper
 * 
 * A Blueprint Function Library class that provides helper functions to interact with actors implementing the ICPP_Interactable interface.
 * These functions allow calling specific interaction actions on a target actor, such as primary, secondary, numeric, and custom key actions.
 */
UCLASS()
class MISPISIT_API UInteractableHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnAttach(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnDetach(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnTouch(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnUnTouch(AActor* Target);
	
	/**
	 * Calls the OnPrimaryAction function on the target actor if it implements the ICPP_Interactable interface.
	 * 
	 * @param Target The actor to interact with. Must implement ICPP_Interactable.
	 */
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnPrimaryAction(AActor* Target);
	
	/**
	 * Calls the OnSecondaryAction function on the target actor if it implements the ICPP_Interactable interface.
	 * 
	 * @param Target The actor to interact with. Must implement ICPP_Interactable.
	 */
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnSecondaryAction(AActor* Target);
	
	/**
	 * Calls the OnNumericAction function on the target actor if it implements the ICPP_Interactable interface.
	 * 
	 * @param Target The actor to interact with. Must implement ICPP_Interactable.
	 * @param Digit The numeric value associated with the action.
	 */
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnNumericAction(AActor* Target, const int Digit);
	
	/**
	 * Calls the OnCustomKeyAction function on the target actor if it implements the ICPP_Interactable interface.
	 * 
	 * @param Target The actor to interact with. Must implement ICPP_Interactable.
	 * @param Key The custom key associated with the action.
	 */
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnCustomKeyAction(AActor* Target, const FKey Key);
};