/*
 * Passengers.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#include "Passenger.h"

namespace elevators
{

Passenger::Passenger(const Direction direction,
                     const FloorNumber destination) noexcept :
mDirection(direction),
mDestination(destination),
mTravelTime(0),
mWaitTime(0)
{
}

Passenger::~Passenger()
{
}

void Passenger::incrementTravelTime() noexcept
{
   ++mTravelTime;
}

void Passenger::incrementWaitTime() noexcept
{
   ++mWaitTime;
}

} /* namespace elevators */
