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

enum class ElevatorState
{
   STOPPED,
   STOPPING,
   MOVING
};

class Elevator
{
public:
   Elevator(unsigned int capacity,
            unsigned int stoppingTime,
            unsigned int movingTime,
            FloorNumber bottomFloor,
            FloorNumber topFloor);
   virtual ~Elevator();

   Direction getDirection() const
   {
      return mDirection;
   }

   void setDirection(const Direction direction)
   {
      mDirection = direction;
   }

   /// Adds a passenger to the elevator and adds the passenger's destination to the list.
   /// Returns false if the elevator is full or the passenger is going in a different direction.
   bool addPassenger(Passenger passenger);

   /// The elevator takes an action, incrementing in time 1 second. If the state changes, time is
   /// reset to zero.
   /// The action is defined based on the current elevator state:
   /// STOPPED: If the direction is not NONE, the state changes to MOVING and moves floors.
   /// STOPPING: If the elevator has been stopping for a enough time, the state changes to STOPPED.
   /// MOVING: If the elevator has been moving for a enough time, the state changes to STOPPING.
   void move();

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
