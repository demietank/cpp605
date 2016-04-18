/*
 * Elevator.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#include <cassert>

#include "Elevator.h"

namespace elevators
{

Elevator::Elevator(unsigned int capacity,
                   unsigned int stoppingTime,
                   unsigned int movingTime,
                   FloorNumber bottomFloor,
                   FloorNumber topFloor) :
      mCapacity(capacity),
      mStoppingTime(stoppingTime),
      mMovingTime(movingTime),
      mState(ElevatorState::STOPPED),
      mTimeInState(0),
      mDirection(Direction::NONE),
      mCurrentFloor(bottomFloor),
      mBottomFloor(bottomFloor),
      mTopFloor(topFloor)
{
}

Elevator::~Elevator()
{
}

bool Elevator::addPassenger(Passenger passenger)
{
   bool status = false;
   if ((mPassengers.size() < mCapacity) && passenger.getDirection() == mDirection)
   {
      mPassengers.emplace_back(passenger);
      status = true;
   }
   return status;
}

void Elevator::move()
{
   ++mTimeInState;

   switch (mState)
   {
   case ElevatorState::STOPPED:
      if (mDirection == Direction::UP)
      {
         ++mCurrentFloor;
         mState = ElevatorState::MOVING;
         mTimeInState = 0;
      }
      else if (mDirection == Direction::DOWN)
      {
         --mCurrentFloor;
         mState = ElevatorState::MOVING;
         mTimeInState = 0;
      }
      break;
   case ElevatorState::STOPPING:
      if (mTimeInState >= mStoppingTime)
      {
         mState = ElevatorState::STOPPED;
         mTimeInState = 0;
      }
      break;
   case ElevatorState::MOVING:
      if (mTimeInState > mMovingTime)
      {
         mState = ElevatorState::STOPPING;
         mTimeInState = 0;
      }
      break;
   default:
   {
      assert(false);
   }
   }
   assert((mCurrentFloor >= mBottomFloor) && (mCurrentFloor <= mTopFloor));
}

} /* namespace elevators */
