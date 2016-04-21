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

std::vector<Passenger> Floor::disembark(FloorNumber currentFloor)
{
   std::vector<Passenger> retVec;

   // don't increment iterator when erasing, use the returned value
   auto it = mPassengers.begin();
   while (it != mPassengers.end())
   {
      if (it->getDestination() == currentFloor)
      {
         retVec.emplace_back(*it);
         it = mPassengers.erase(it);
      }
      else
      {
         ++it;
      }
   }

   return retVec;
}

bool Floor::hasPassengers() const noexcept
{
   return !mPassengers.empty();
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
   // don't increment iterator when erasing, use the returned value
   auto it = mPassengers.begin();
   while (it != mPassengers.end())
   {
      if (elevator.addPassenger(*it))
      {
         it = mPassengers.erase(it);
      }
      else
      {
         ++it;
      }
   }
}

std::ostream& operator<<(std::ostream& out,
                         const Floor& floor)
{
   for (const auto& passenger : floor.mPassengers)
   {
      out << passenger;
   }
   return out;
}

} /* namespace elevators */
