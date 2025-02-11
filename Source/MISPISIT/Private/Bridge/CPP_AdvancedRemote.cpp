// CPP_AdvancedRemote.cpp

#include "Bridge/CPP_AdvancedRemote.h"

bool ACPP_AdvancedRemote::Mute()
{
	if (!DeviceInterface)
	{
		return false;
	}

	if (DeviceInterface->GetVolume() > 0.01f)
	{
		CachedVolume = DeviceInterface->GetVolume();
		return DeviceInterface->SetVolume(0);
	}
	else
	{
		return DeviceInterface->SetVolume(CachedVolume);
	}
}

bool ACPP_AdvancedRemote::OnNumericAction(const int Digit)
{
	if (Digit == 6)
	{
		return Mute();
	}
	
	return Super::OnNumericAction(Digit);
}

