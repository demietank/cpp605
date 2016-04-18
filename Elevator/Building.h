/*
 * Building.h
 *
 *  Created on: Apr 15, 2016
 *      Author: cmmay
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include <set>
#include <vector>

#include "common.h"
#include "Floor.h"
#include "Elevator.h"

namespace elevators
{

class Building
{
public:
   Building(FloorNumber bottomFloor,
            FloorNumber topFloor,
            unsigned int numElevators,
            Elevator elevator);
   virtual ~Building();

   void makeFloorRequest(FloorNumber floor,
                         Direction dir);
private:
   /// Floors of the building (contiguous)
   FloorNumber mBottomFloor;
   FloorNumber mTopFloor;

   std::vector<Elevator> mElevators;
   std::vector<Floor> mFloors;

   /// Floors that have requested an elevator going in a direction.
   std::set<FloorNumber> mFloorRequestsUp;
   std::set<FloorNumber> mFloorRequestsDown;
};

} /* namespace elevators */

#endif /* BUILDING_H_ */
