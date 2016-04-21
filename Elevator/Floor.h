/*
 * Floors.h
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#ifndef FLOOR_H_
#define FLOOR_H_

#include <ostream>
#include <vector>

#include "Elevator.h"
#include "Passenger.h"

namespace elevators
{

/// A floor that contains passengers waiting to travel to another floor.
class Floor
{
public:
   /// Constructs an empty floor.
   Floor();

   /// Destructs the floor.
   virtual ~Floor();

   /// Adds a passenger to the floor
   void addPassenger(const Passenger& passenger);

   /// Removes passengers whose destination is the current floor, if any.
   std::vector<Passenger> disembark(FloorNumber currentFloor);

   /// Returns true if the floor has passengers waiting for transport.
   bool hasPassengers() const noexcept;

   /// Increment wait time for all passengers.
   void incrementPassengerTime() noexcept;

   /// Attempt to move as many passengers as possible to the elevator.
   void movePassengersToElevator(Elevator& elevator);

private:
   /// Passengers on the floor.
   std::vector<Passenger> mPassengers;

   /// Outputs an ASCII representation of the floor.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Floor& floor);
};

/// Outputs an ASCII representation of the floor.
std::ostream& operator<<(std::ostream& out,
                         const Floor& floor);

} /* namespace elevators */

#endif /* FLOOR_H_ */
