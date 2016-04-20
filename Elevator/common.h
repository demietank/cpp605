/*
 * common.h
 *
 *  Created on: Apr 17, 2016
 *      Author: cmmay
 */

#ifndef COMMON_H_
#define COMMON_H_

namespace elevators
{

/// Possible directions of travel.
enum class Direction
{
   NONE,
   DOWN,
   UP
};

/// A convenient way to identify floors in a building.
using FloorNumber = int;

} /* namespace elevators */
#endif /* COMMON_H_ */
