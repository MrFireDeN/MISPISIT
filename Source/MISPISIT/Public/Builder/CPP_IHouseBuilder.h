#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_IHouseBuilder.generated.h"

/**
 * @brief Blueprintable interface for building houses. 
 * Provides methods for setting walls, doors, windows, and roofs.
 */
UINTERFACE(Blueprintable, BlueprintType) 
class MISPISIT_API UCPP_IHouseBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * @brief Interface class for implementing house building logic.
 * Implement this interface in your classes to define how houses are built.
 */
class MISPISIT_API ICPP_IHouseBuilder
{
	GENERATED_BODY()

public:
	/**
	 * @brief Sets the dimensions of the walls.
	 * @param Length The length of the walls.
	 * @param Width The width of the walls.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HouseBuilder")
	bool SetWalls(int Length, int Width);

	/**
	 * @brief Sets the number of doors.
	 * @param Count The number of doors.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HouseBuilder")
	bool SetDoors(int Count);

	/**
	 * @brief Sets the number of windows.
	 * @param Count The number of windows.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HouseBuilder")
	bool SetWindows(int Count);

	/**
	 * @brief Sets the height of the roof.
	 * @param Height The height of the roof.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HouseBuilder")
	bool SetRoof(int Height);

	/**
	 * @brief Resets the builder to its initial state.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HouseBuilder")
	bool Reset();
};
