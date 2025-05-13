// MICommand.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MICommand.generated.h"

/**
 * Command Pattern Interface for implementing undoable actions
 * 
 * This interface provides the base contract for commands in a command pattern implementation,
 * allowing execution and reversal of operations. Commonly used for:
 * - AI behavior commands
 * - Gameplay action systems
 * - Undo/Redo functionality in editors
 */
UINTERFACE()
class UMICommand : public UInterface
{
	GENERATED_BODY()
};

/**
 * Command interface for executable and reversible actions
 * 
 * Implement this interface to create concrete command classes that can:
 * - Execute specific gameplay actions
 * - Reverse their effects when needed
 * - Be managed by command queues or history systems
 */
class MISPISIT_API IMICommand
{
	GENERATED_BODY()

public:
	/**
	 * Executes the command's primary action
	 * 
	 * Implement this to define what happens when the command is invoked.
	 * This is typically where you:
	 * - Modify game state
	 * - Trigger animations or effects
	 * - Change AI behavior
	 * 
	 * @note Always implement this as BlueprintNativeEvent for flexibility
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Command")
	void Execute();

	/**
	 * Reverses the effects of this command
	 * 
	 * Implement this to undo whatever changes Execute() made.
	 * This should:
	 * - Restore previous state
	 * - Cancel ongoing actions
	 * - Return objects to pre-execution conditions
	 * 
	 * @note Should maintain all necessary state to perform the undo
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Command")
	void Undo();
};