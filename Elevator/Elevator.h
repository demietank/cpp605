/*
 * Elevator.h
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include <set>
#include <vector>

#include "common.h"
#include "Passenger.h"

namespace elevators
{

/// States the elevator can be in.
enum class ElevatorState
{
   STOPPED,
   STOPPING,
   MOVING
};

/// An elevator that moves between floors transporting passengers.
class Elevator
{
public:
   /// Constructs an empty elevator, stopped at the bottom floor.
   Elevator(const unsigned int capacity,
            const unsigned int stoppingTime,
            const unsigned int movingTime,
            const FloorNumber bottomFloor,
            const FloorNumber topFloor);

   /// Destructs the elevator.
   virtual ~Elevator();

   /// Adds the specified floor to the elevator's destination list.
   /// If the elevator's direction is none, change the direction toward the new destination.
   /// Returns false if the elevator is going in a different direction or is already stopped on the floor.
   bool addDestination(const FloorNumber floor);

   /// Adds a passenger to the elevator and adds the passenger's destination to the list.
   /// Returns false if the elevator is full or the passenger is going in a different direction.
   bool addPassenger(const Passenger& passenger);

   /// Removes passengers whose destination is the current floor, if any.
   /// The current floor is removed from the destination list.
   /// If there are no more passengers or destinations, change the direction to none.
   std::vector<Passenger> disembark();

   /// Increment travel time for all passengers.
   void incrementPassengerTime();

   /// The elevator takes an action, incrementing in time 1 second. If the state changes, time is
   /// reset to zero.
   /// The action is defined based on the current elevator state:
   /// STOPPED:  If the direction is not NONE, the state changes to MOVING and moves floors.
   /// STOPPING: If the elevator has been stopping for a enough time, the state changes to STOPPED.
   /// MOVING:   If the elevator has been moving for a enough time
   ///              If the new floor is in the destination list, the state changes to STOPPING.
   ///              Otherwise the elevator moves floors.
   void move();

   /// Returns the direction the elevator is traveling in.
   Direction getDirection() const
   {
      return mDirection;
   }

   /// Returns the current floor the elevator is on.
   FloorNumber getFloor() const
   {
      return mCurrentFloor;
   }

   /// Returns the state of the elevator.
   ElevatorState getState() const
   {
      return mState;
   }

private:
   /// Number of passengers the elevator can carry at once.
   unsigned int mCapacity;

   /// The time it takes the elevator to stop
   unsigned int mStoppingTime;

   /// The time it takes the elevator to move between floors
   unsigned int mMovingTime;

   /// The state of the elevator, and the time it has spend there
   ElevatorState mState;
   unsigned int mTimeInState;
   Direction mDirection;

   /// The floor the elevator is on.
   /// If the elevator is in transport this is the next floor it will arrive on.
   FloorNumber mCurrentFloor;

   /// Floors the elevator services (contiguous)
   FloorNumber mBottomFloor;
   FloorNumber mTopFloor;

   /// Passengers in the elevator
   std::vector<Passenger> mPassengers;

   /// Floors that the elevator will stop on
   std::set<FloorNumber> mDestinations;
};

} /* namespace elevators */

#endif /* ELEVATOR_H_ */
