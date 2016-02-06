/*
 * Statistics.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Chris
 */

#include <cassert>
#include <climits>
#include <iostream>

#include "Statistics.h"

Statistics::Statistics() :
      mTotal(0),
      mNumElements(0)
{
}

Statistics::~Statistics()
{
}

bool Statistics::addNumber(int num)
{
   bool status;

   if ((mTotal > 0) && (num > (INT_MAX - mTotal)))
   {
      std::cerr << "Operation would cause overflow, rejected" << std::endl;
      status = false;
   }
   else if ((mTotal < 0) && (num < (INT_MIN - mTotal)))
   {
      std::cerr << "Operation would cause underflow, rejected" << std::endl;
      status = false;
   }
   else if (mNumElements == UINT_MAX)
   {
      std::cerr << "The pattern is full, rejected" << std::endl;
      status = false;
   }
   else
   {
      mTotal += num;
      mNumElements++;
      status = true;
   }

   return status;
}

double Statistics::getAverage() const
{
   assert(mNumElements != 0);
   return static_cast<double>(mTotal) / mNumElements;
}

double Statistics::getStdDev() const
{
   assert(mNumElements != 0);

   return 0;
}

