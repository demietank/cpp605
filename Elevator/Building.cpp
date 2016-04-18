/*
 * Building.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: cmmay
 */

#include "Building.h"

namespace elevators
{

Building::Building(FloorNumber bottomFloor,
                   FloorNumber topFloor,
                   unsigned int numElevators,
                   Elevator elevator) :
                         mBottomFloor(bottomFloor),
                         mTopFloor(topFloor),
                         mElevators(numElevators, elevator)
{
}

Building::~Building()
{
}

} /* namespace elevators */
