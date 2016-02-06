/*
 * Statistics.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Chris
 */

#include <cassert>
#include <iostream>
#include <cmath>
#include <numeric>

#include "Statistics.h"

Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}

bool Statistics::addNumber(int num)
{
   try
   {
      mSequence.emplace_back(num);
      return true;
   }
   catch (std::bad_alloc& ba)
   {
     std::cerr << "Failed to add " << num << "; bad_alloc caught: " << ba.what() << std::endl;
     return false;
   }
}

double Statistics::getAverage() const
{
   assert(!mSequence.empty());
   long long sum = 0; //force the return type to be long long

   sum = std::accumulate(mSequence.begin(), mSequence.end(), sum);
   return static_cast<double>(sum) / mSequence.size();
}

double Statistics::getStdDev() const
{
   assert(!mSequence.empty());

   const double avg = getAverage();
   double sumDeviaton = 0.0;

   for (const auto& i : mSequence)
   {
      sumDeviaton += pow((i - avg), 2);
   }

   return sqrt(sumDeviaton / mSequence.size());
}

