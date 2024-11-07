// CPP_BuildingFactory.cpp

#include "House/CPP_BuildingFactory.h"

/**
 * @brief Creates a new instance of ACPP_Door with specified dimensions.
 * 
 * @param Transform The width of the door in meters.
 * 
 * @return nullptr, as the default implementation does not create a door instance.
 */
ACPP_Door* UCPP_BuildingFactory::CreateDoor(FTransform Transform)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Roof with specified dimensions.
 * 
 * @param Length The length of the roof in meters.
 * @param Width The width of the roof in meters.
 * 
 * @return nullptr, as the default implementation does not create a roof instance.
 */
ACPP_Roof* UCPP_BuildingFactory::CreateRoof(float Length, float Width)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Wall with specified dimensions.
 * 
 * @param Transform
 * @param WallType
 * 
 * @return nullptr, as the default implementation does not create a wall instance.
 */
ACPP_Wall* UCPP_BuildingFactory::CreateWall(FTransform Transform, EWallType WallType)
{
 return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Window with specified dimensions.
 * 
 * @param Width The width of the window in meters.
 * @param Height The height of the window in meters.
 * 
 * @return nullptr, as the default implementation does not create a window instance.
 */
ACPP_Window* UCPP_BuildingFactory::CreateWindow(float Width, float Height)
{
 return nullptr;
}
