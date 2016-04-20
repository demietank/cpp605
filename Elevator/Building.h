/*
 * Building.h
 *
 *  Created on: Apr 15, 2016
 *      Author: cmmay
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include <map>
#include <vector>

#include "common.h"
#include "Floor.h"
#include "Elevator.h"

namespace elevators
{

/// A building that contains floors and elevators. This is the hub that contains
/// the simulation.
class Building
{
public:
   /// Constructs an empty building consisting of floors and elevators.
   /// The elevator parameter identifies the qualities common to all elevators.
   Building(const FloorNumber bottomFloor,
            const FloorNumber topFloor,
            const unsigned int numElevators,
            const Elevator& elevator);
   virtual ~Building();

   /// Adds a passenger to a floor.
   void addPassenger(const Passenger& passenger, const FloorNumber floor);

   /// Adds passengers to elevators stopped on their floor.
   void addPassengersToElevators();

   /// Identify elevators stopped at floors.
   /// Removes passengers from all elevators whose destination is the current floor, if any.
   std::vector<Passenger> disembark();

   /// Increment the travel and wait times for all passengers.
   void incrementPassengerTime();

   /// Update elevator destination lists.
   /// For each passenger on each floor, add their current floor to all elevators traveling
   /// in that direction or stopped. Duplicates are expected.
   void updateElevatorDestinations();

private:
   /// Floors of the building (contiguous)
   FloorNumber mBottomFloor;
   FloorNumber mTopFloor;

   /// Container, keyed by floor number
   std::map<FloorNumber, Floor> mFloors;

   /// Elevators in the building
   std::vector<Elevator> mElevators;
};

} /* namespace elevators */

#endif /* BUILDING_H_ */
