/*
 * Building.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: cmmay
 */

#include <cassert>

#include "Building.h"

namespace elevators
{

Building::Building(const FloorNumber bottomFloor,
                   const FloorNumber topFloor,
                   const unsigned int numElevators,
                   const Elevator& elevator) :
      mBottomFloor(bottomFloor),
      mTopFloor(topFloor),
      mElevators(numElevators, elevator)
{
   assert(mTopFloor > mBottomFloor);
   for (FloorNumber i = bottomFloor; i <= topFloor; ++i)
   {
      mFloors.emplace(i, Floor());
   }
}

Building::~Building()
{
}

void Building::addPassenger(const Passenger& passenger,
                            const FloorNumber floor)
{
   assert((floor <= mTopFloor) && (floor >= mBottomFloor));
   mFloors.at(floor).addPassenger(passenger);
}

void Building::addPassengersToElevators()
{
   for (auto& elevator : mElevators)
   {
      if (elevator.getState() == ElevatorState::STOPPED)
      {
         mFloors.at(elevator.getFloor()).movePassengersToElevator(elevator);
      }
   }
}

std::vector<Passenger> Building::disembark()
{
   std::vector<Passenger> retVec;

   for (auto& elevator : mElevators)
   {
      if (elevator.getState() == ElevatorState::STOPPED)
      {
         auto elevatorVec = elevator.disembark();
         retVec.insert(retVec.end(), std::make_move_iterator(elevatorVec.begin()),
               std::make_move_iterator(elevatorVec.end()));
      }
   }

   return retVec;
}

void Building::incrementPassengerTime()
{
   for (auto& elevator : mElevators)
   {
      elevator.incrementPassengerTime();
   }

   for (auto& floor : mFloors)
   {
      floor.second.incrementPassengerTime();
   }
}

void Building::updateElevatorDestinations()
{
   for (const auto& floor : mFloors)
   {
      for (const auto& passenger : floor.second.getPassengers())
      {
         for (auto& elevator : mElevators)
         {
            elevator.addDestination(passenger.getDestination());
         }
      }
   }
}

} /* namespace elevators */
