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

class Passenger
{
public:
   Passenger(const Direction direciton,
             const FloorNumber destination);

   virtual ~Passenger();

   Direction getDirection() const
   {
      return mDirection;
   }

   FloorNumber getDestination() const
   {
      return mDestination;
   }

   unsigned int getTravelTime() const
   {
      return mTravelTime;
   }

   void setTravelTime(const unsigned int travelTime)
   {
      mTravelTime = travelTime;
   }

   unsigned int getWaitTime() const
   {
      return mWaitTime;
   }

   void setWaitTime(const unsigned int waitTime)
   {
      mWaitTime = waitTime;
   }

   void moveInTime(const bool traveling);

private:
   Direction mDirection;
   FloorNumber mDestination;

   unsigned int mTravelTime;
   unsigned int mWaitTime;
};

} /* namespace elevators */

#endif /* PASSENGER_H_ */
