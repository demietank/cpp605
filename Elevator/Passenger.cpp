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
                     const FloorNumber destination) :
                           mDirection(direction),
                           mDestination(destination),
                           mTravelTime(0),
                           mWaitTime(0)
{
}

Passenger::~Passenger()
{
}

void Passenger::moveInTime(const bool traveling)
{
   if (traveling)
   {
      ++mTravelTime;
   }
   else
   {
      ++mWaitTime;
   }
}

} /* namespace elevators */
