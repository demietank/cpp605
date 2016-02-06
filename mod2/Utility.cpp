/*
 * Utility.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Chris
 */

#include <cmath>

#include "Utility.h"

bool Utility::isEqual(const double a, const double b)
{
   constexpr const double DELTA = 1.0 / 1000000.0;

   if (fabs(a - b) < DELTA)
   {
      return true;
   }
   else
   {
      return false;
   }
}
