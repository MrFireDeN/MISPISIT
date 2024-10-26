// CPP_Window.cpp

#include "House/CPP_Window.h"

/**
 * @brief Toggles the light associated with the window, displaying a message indicating its new state.
 * 
 * Calls IsLightOn() to check the current state. If the light is on, it turns it off and prints "Light off";
 * if it’s off, it turns it on and prints "Light on". Override this method to implement real light control.
 */
void ACPP_Window::ToggleLight()
{
	if (IsLightOn())
	{
		UKismetSystemLibrary::PrintString(this, Name + ": Light off");
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, Name + ": Light on");
	}
}

/**
 * @brief Returns whether the window's light is currently on.
 * 
 * Default implementation always returns false, indicating the light is off.
 * Override this method to provide actual light state management.
 * 
 * @return false, indicating the light is off by default.
 */
bool ACPP_Window::IsLightOn()
{
	return false;
}
