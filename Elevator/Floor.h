/*
 * Floors.h
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#ifndef FLOOR_H_
#define FLOOR_H_

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

   /// Returns a constant reference to the private passenger list.
   const std::vector<Passenger>& getPassengers() const
   {
      return mPassengers;
   }

   /// Increment wait time for all passengers.
   void incrementPassengerTime() noexcept;

   /// Attempt to move as many passengers as possible to the elevator.
   void movePassengersToElevator(Elevator& elevator);

private:
   /// Passengers on the floor.
   std::vector<Passenger> mPassengers;
};

} /* namespace elevators */

#endif /* FLOOR_H_ */
