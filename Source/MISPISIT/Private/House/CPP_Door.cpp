// CPP_Door.cpp

#include "House/CPP_Door.h"

/**
 * @brief Toggles the door's state between open and closed, with a message indicating the new state.
 * 
 * Calls IsOpen() to check the current state. If the door is open, it prints "Door closed"; if closed,
 * it prints "Door opened". Override this function to implement actual door state tracking.
 */
void ACPP_Door::Toggle()
{
	if (IsOpen())
	{
		UKismetSystemLibrary::PrintString(this, Name + ": closed");
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, Name + ": opened");
	}
}

/**
 * @brief Returns whether the door is open. 
 * 
 * Default implementation always returns false, meaning the door is closed.
 * Override this function to return the actual state of the door.
 * 
 * @return false, indicating the door is closed by default.
 */
bool ACPP_Door::IsOpen()
{
	return false;
}
