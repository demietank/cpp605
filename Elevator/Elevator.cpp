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
   assert(mTopFloor > mBottomFloor);
}

Elevator::~Elevator()
{
}

bool Elevator::addDestination(const FloorNumber floor)
{
   assert((floor >= mBottomFloor) && (floor <= mTopFloor));
   bool status = true;

   if ((mState == ElevatorState::STOPPED) && (mCurrentFloor == floor))
   {
      status = false;
   }
   else if ((mDirection == Direction::UP) && (mCurrentFloor > floor))
   {
      status = false;
   }
   else if ((mDirection == Direction::DOWN) && (mCurrentFloor < floor))
   {
      status = false;
   }
   else
   {
      // update direction, if necessary
      if (mDirection == Direction::NONE)
      {
         assert(mState == ElevatorState::STOPPED);
         mDirection = mCurrentFloor < floor ? Direction::UP : Direction::DOWN;
      }

      // ignore if already in list
      (void) mDestinations.emplace(floor);
   }

   return status;
}

bool Elevator::addPassenger(const Passenger& passenger)
{
   assert(mState == ElevatorState::STOPPED);
   bool status = false;

   if (mPassengers.size() < mCapacity)
   {
      if (addDestination(passenger.getDestination()))
      {
         mPassengers.emplace_back(passenger);
         status = true;
      }
   }

   return status;
}

std::vector<Passenger> Elevator::disembark()
{
   assert(mState == ElevatorState::STOPPED);
   std::vector<Passenger> retVec;
   for (auto it = mPassengers.begin(); it != mPassengers.end(); ++it)
   {
      if (it->getDestination() == mCurrentFloor)
      {
         retVec.emplace_back(*it);
         mPassengers.erase(it);
      }
   }

   mDestinations.erase(mCurrentFloor);

   if (mPassengers.empty())
   {
      mDirection = Direction::NONE;
   }

   return retVec;
}

void Elevator::incrementPassengerTime()
{
   for (auto& passenger : mPassengers)
   {
      passenger.incrementTravelTime();
   }
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
      assert(mDirection != Direction::NONE);
      if (mTimeInState >= mMovingTime)
      {
         if (mDestinations.count(mCurrentFloor))
         {
            mState = ElevatorState::STOPPING;
         }
         else
         {
            if (mDirection == Direction::UP)
            {
               ++mCurrentFloor;
            }
            else if (mDirection == Direction::DOWN)
            {
               --mCurrentFloor;
            }
         }
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
