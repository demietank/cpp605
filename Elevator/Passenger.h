/*
 * Passengers.h
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "common.h"

namespace elevators
{

/// A passenger riding an elevator trying to reach a destination.
/// A passenger is a dumb object that is moved by the almighty.
class Passenger
{
public:
   /// Constructs a passenger.
   Passenger(const Direction direction,
             const FloorNumber destination) noexcept;

   virtual ~Passenger();

   /// Returns the direction the passenger is traveling.
   Direction getDirection() const noexcept
   {
      return mDirection;
   }

   /// Returns the destination the passenger is traveling to.
   FloorNumber getDestination() const noexcept
   {
      return mDestination;
   }

   /// Returns the total time the passenger has spent traveling.
   unsigned int getTravelTime() const noexcept
   {
      return mTravelTime;
   }

   /// Returns the total time the passenger has spent waiting for an elevator.
   unsigned int getWaitTime() const noexcept
   {
      return mWaitTime;
   }

   /// Increment the travel time by one second.
   void incrementTravelTime() noexcept;

   /// Increment the wait time by one second.
   void incrementWaitTime() noexcept;

private:
   /// Direction the passenger is traveling in.
   Direction mDirection;

   /// Destination floor of the passenger.
   FloorNumber mDestination;

   /// Time the passenger has spent traveling.
   unsigned int mTravelTime;

   /// Time the passenger has spent waiting for an elevator.
   unsigned int mWaitTime;
};

} /* namespace elevators */

#endif /* PASSENGER_H_ */
