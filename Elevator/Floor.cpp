/*
 * Floors.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#include "Floor.h"

namespace elevators
{

Floor::Floor()
{
}

Floor::~Floor()
{
}

void Floor::addPassenger(const Passenger& passenger)
{
   mPassengers.emplace_back(passenger);
}

void Floor::incrementPassengerTime() noexcept
{
   for (auto& passenger : mPassengers)
   {
      passenger.incrementWaitTime();
   }
}

void Floor::movePassengersToElevator(Elevator& elevator)
{
   for (auto it = mPassengers.begin(); it != mPassengers.end(); ++it)
   {
      if (elevator.addPassenger(*it))
      {
         mPassengers.erase(it);
      }
   }
}

} /* namespace elevators */
