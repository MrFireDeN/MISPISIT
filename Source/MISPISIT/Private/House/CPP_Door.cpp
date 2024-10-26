#include "House/CPP_Door.h"

void ACPP_Door::Toggle()
{
	if (IsOpen())
	{
		UKismetSystemLibrary::PrintString(this, "Door closed");
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, "Door opened");
	}
}

bool ACPP_Door::IsOpen()
{
	return false;
}
