/*
 * Floors.h
 *
 *  Created on: Apr 14, 2016
 *      Author: cmmay
 */

#ifndef FLOOR_H_
#define FLOOR_H_

#include "Passenger.h"

namespace elevators
{

class Floor
{
public:
   Floor();
   virtual ~Floor();

   void addPassenger(Passenger passenger);
};

} /* namespace elevators */

#endif /* FLOOR_H_ */
