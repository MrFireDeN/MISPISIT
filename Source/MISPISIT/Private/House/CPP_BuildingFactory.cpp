// CPP_BuildingFactory.cpp

#include "House/CPP_BuildingFactory.h"

/**
 * @brief Creates a new instance of ACPP_Door.
 * 
 * Default implementation returns nullptr. Override in a subclass to provide specific creation logic.
 * 
 * @return nullptr, as the default implementation does not create a door instance.
 */
ACPP_Door* UCPP_BuildingFactory::CreateDoor()
{
	return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Roof.
 * 
 * Default implementation returns nullptr. Override in a subclass to provide specific creation logic.
 * 
 * @return nullptr, as the default implementation does not create a roof instance.
 */
ACPP_Roof* UCPP_BuildingFactory::CreateRoof()
{
	return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Wall.
 * 
 * Default implementation returns nullptr. Override in a subclass to provide specific creation logic.
 * 
 * @return nullptr, as the default implementation does not create a wall instance.
 */
ACPP_Wall* UCPP_BuildingFactory::CreateWall()
{
	return nullptr;
}

/**
 * @brief Creates a new instance of ACPP_Window.
 * 
 * Default implementation returns nullptr. Override in a subclass to provide specific creation logic.
 * 
 * @return nullptr, as the default implementation does not create a window instance.
 */
ACPP_Window* UCPP_BuildingFactory::CreateWindow()
{
	return nullptr;
}
