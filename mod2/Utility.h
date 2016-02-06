/*
 * Utility.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Chris
 */

#ifndef UTILITY_H_
#define UTILITY_H_

/**
 * @brief All functions must go in a class...
 */
class Utility
{
public:
   /**
    * @brief Determines the equality of two doubles, accounting for minute deltas.
    * @return True if the doubles can be considered equal.
    */
   static bool isEqual(const double a, const double b);
};

#endif /* UTILITY_H_ */
