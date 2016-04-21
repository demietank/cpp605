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

   // catch any passengers who mistakenly got on the elevator
   for (auto& floor : mFloors)
   {
      auto floorVec = floor.second.disembark(floor.first);
      retVec.insert(retVec.end(), std::make_move_iterator(floorVec.begin()),
            std::make_move_iterator(floorVec.end()));
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

void Building::moveElevators()
{
   for (auto& elevator : mElevators)
   {
      elevator.move();
   }
}

void Building::updateElevatorDestinations()
{
   for (const auto& floor : mFloors)
   {
      //if (!floor.second.getPassengers().empty())
      if (floor.second.hasPassengers())
      {
         for (auto& elevator : mElevators)
         {
            elevator.addDestination(floor.first);
         }
      }
   }
}

std::ostream& operator<<(std::ostream& out,
                         const Building& building)
{
   constexpr auto BORDER = "------------------------";

   out << BORDER << std::endl;
   for (const auto& floor : building.mFloors)
   {
      out << floor.first << ": " << floor.second << std::endl;
   }

   for (const auto& elevator : building.mElevators)
   {
      out << elevator << std::endl;
   }
   out << BORDER << std::endl;

   return out;
}

} /* namespace elevators */
