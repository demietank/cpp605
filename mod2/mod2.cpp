/*
 * mod1.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#include <climits>
#include <iostream>

#include "Statistics.h"
#include "Utility.h"

/**
 * @brief Entry point to module 2 test.
 */
int main()
{
   bool success = true;

   std::cout << "Running module 2 test..." << std::endl;

#if 0
   // negative testing (compiler rejected)
   Statistics statsNeg1;
   if (statsNeg1.addNumber(INT_MAX+1)
         || statsNeg1.addNumber(INT_MIN-1))
   {
      std::cerr << "Failed to reject integer out of bounds" << std::endl;
      success = false;
   }
#endif



#if 0
   // negative testing (assert rejected)
   Statistics statsNeg2;
   auto avgFail = statsNeg2.getAverage();
   (void)avgFail;
   auto stddevFail = statsNeg2.getStdDev();
   (void)stddevFail;
#endif

   // negative testing (logic rejected)
   Statistics statsNeg3;
   statsNeg3.addNumber(INT_MAX);
   if (statsNeg3.addNumber(1))
   {
      std::cerr << "Failed to reject total overflow" << std::endl;
      success = false;
   }

   Statistics statsNeg4;
   statsNeg4.addNumber(INT_MIN);
   if (statsNeg4.addNumber(-1))
   {
      std::cerr << "Failed to reject total underflow" << std::endl;
      success = false;
   }

   Statistics statsNeg5;
   for (unsigned int i = 0; i < UINT_MAX; i++)
   {
      // Average 0 to ensure the number of elements is tested, not count
      int toAdd = (i % 2 == 0) ? 1 : -1;
      if (!statsNeg5.addNumber(toAdd))
      {
         std::cerr << "Unexpected error adding element 0x" << std::hex << i << std::dec << std::endl;
         success = false;
         break;
      }
   }
   if (statsNeg5.addNumber(1))
   {
      std::cerr << "Failed to reject number of elements overflow" << std::endl;
      success = false;
   }

   // Test results
   auto avg = statsNeg5.getAverage();
   if (!Utility::isEqual(avg, 0.0))
   {
      std::cerr << "Avg failure: Expected: 0.0, Calc: " << avg << std::endl;
      success = false;
   }


   if (success)
   {
      std::cout << "tests passed" << std::endl;
   }
   else
   {
      std::cout << "tests failed" << std::endl;
   }
   return 0;
}
