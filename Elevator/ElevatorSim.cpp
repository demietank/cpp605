/*
 * ElevatorSim.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: cmmay
 */

#include "ElevatorSim.h"

namespace elevators
{

} /* namespace elevators */

/**
 * @brief Entry point to the expression tree test.
 */
int main()
{
   using namespace elevators;
   constexpr FloorNumber BOTTOM_FLOOR = 0;
   constexpr FloorNumber TOP_FLOOR = 100;
   constexpr unsigned int NUM_ELEVATORS = 4;
   constexpr unsigned int ELEVATOR_STOPPING_TIME = 2;
   constexpr unsigned int ELEVATOR_MOVING_TIME = 10;
   constexpr unsigned int ELEVATOR_CAPACITY = 8;

   Building building = Building(BOTTOM_FLOOR, TOP_FLOOR, NUM_ELEVATORS, { ELEVATOR_CAPACITY,
         ELEVATOR_STOPPING_TIME, ELEVATOR_MOVING_TIME, BOTTOM_FLOOR, TOP_FLOOR });

   return 0;
}
