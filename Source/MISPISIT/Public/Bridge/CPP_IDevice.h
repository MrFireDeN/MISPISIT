#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_IDevice.generated.h"

/**
 * UCPP_IDevice
 * 
 * Interface defining the basic methods for controlling devices.
 * Can be used to implement control for various types of devices,
 * such as radios, televisions, and other devices supporting channels and volume adjustments.
 */
UINTERFACE(Blueprintable)
class UCPP_IDevice : public UInterface
{
	GENERATED_BODY()
};

/**
 * ICPP_IDevice
 * 
 * Interface for device management.
 * Implement this interface in your classes to support turning devices on/off, 
 * adjusting volume, and changing channels.
 */
class MISPISIT_API ICPP_IDevice
{
	GENERATED_BODY()

public:
	/**
	 * Checks if the device is enabled.
	 * 
	 * @return true if the device is enabled, otherwise false.
	 */
	virtual bool IsEnabled() = 0;

	/**
	 * Enables the device.
	 * 
	 * @return true if the operation is successful, otherwise false.
	 */
	virtual bool Enable() = 0;

	/**
	 * Disables the device.
	 * 
	 * @return true if the operation is successful, otherwise false.
	 */
	virtual bool Disable() = 0;

	/**
	 * Gets the current volume of the device.
	 * 
	 * @return The current volume (as a percentage from 0 to 100).
	 */
	virtual int GetVolume() = 0;

	/**
	 * Sets the device volume.
	 * 
	 * @param NewVolume The new volume value (as a percentage from 0 to 100).
	 * @return true if the operation is successful, otherwise false.
	 */
	virtual bool SetVolume(const int& NewVolume) = 0;

	/**
	 * Gets the current channel of the device.
	 * 
	 * @return The current channel number.
	 */
	virtual int GetChannel() = 0;

	/**
	 * Sets the current channel of the device.
	 * 
	 * @param NewChannel The new channel number.
	 * @return true if the operation is successful, otherwise false.
	 */
	virtual bool SetChannel(const int& NewChannel) = 0;
};
