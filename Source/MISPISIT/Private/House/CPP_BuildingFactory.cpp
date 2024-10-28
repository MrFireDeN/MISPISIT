// CPP_BuildingFactory.cpp

#include "House/CPP_BuildingFactory.h"

/**
 * @brief Creates a new instance of ACPP_Door with specified dimensions.
 * 
 * @param World The world context in which the door should be spawned.
 * @param Width The width of the door in meters.
 * @param Height The height of the door in meters.
 * 
 * @return nullptr, as the default implementation does not create a door instance.
 */
ACPP_Door* UCPP_BuildingFactory::CreateDoor(UWorld* World, float Width, float Height)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Roof with specified dimensions.
 * 
 * @param World The world context in which the roof should be spawned.
 * @param Length The length of the roof in meters.
 * @param Width The width of the roof in meters.
 * 
 * @return nullptr, as the default implementation does not create a roof instance.
 */
ACPP_Roof* UCPP_BuildingFactory::CreateRoof(UWorld* World, float Length, float Width)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Wall with specified dimensions.
 * 
 * @param World The world context in which the wall should be spawned.
 * @param Length The length of the wall in meters.
 * @param Width The width of the wall in meters.
 * @param Height The height of the wall in meters.
 * 
 * @return nullptr, as the default implementation does not create a wall instance.
 */
ACPP_Wall* UCPP_BuildingFactory::CreateWall(UWorld* World, float Length, float Width, float Height)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Window with specified dimensions.
 * 
 * @param World The world context in which the window should be spawned.
 * @param Width The width of the window in meters.
 * @param Height The height of the window in meters.
 * 
 * @return nullptr, as the default implementation does not create a window instance.
 */
ACPP_Window* UCPP_BuildingFactory::CreateWindow(UWorld* World, float Width, float Height)
{
 return nullptr;
}
