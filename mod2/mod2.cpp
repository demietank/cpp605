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
   // negative testing (assert rejected)
   Statistics statsNeg1;
   auto avgFail = statsNeg1.getAverage();
   (void)avgFail;
   auto stddevFail = statsNeg1.getStdDev();
   (void)stddevFail;
#endif

   // try and force an overflow to check error handling
   Statistics statsNeg2;
   for (unsigned int i = 0; i < UINT_MAX; i++)
   {
      if (!statsNeg2.addNumber(i))
      {
         break;
      }
   }

   // Test set of -1 and 1
   Statistics statsTest1;
   constexpr const unsigned int MAX_TESTS = 0x8000000;
   constexpr const double AVG_EXPECTED1 = 0.0;
   constexpr const double STD_DEV_EXPECTED1 = 1.0;
   for (unsigned int i = 0; i < MAX_TESTS; i++)
   {
      // Average 0 to ensure the number of elements is tested, not count
      int toAdd = (i % 2 == 0) ? 1 : -1;
      if (!statsTest1.addNumber(toAdd))
      {
         std::cerr << "Unexpected error adding element 0x" << std::hex << i << std::dec
               << std::endl;
         success = false;
         break;
      }
   }

   double avg1 = statsTest1.getAverage();
   if (!Utility::isEqual(avg1, AVG_EXPECTED1))
   {
      std::cerr << "Avg failure: Expected: " << AVG_EXPECTED1 << ", Calc: " << avg1 << std::endl;
      success = false;
   }

   double stddev1 = statsTest1.getStdDev();
   if (!Utility::isEqual(stddev1, STD_DEV_EXPECTED1))
   {
      std::cerr << "StdDev failure: Expected: " << STD_DEV_EXPECTED1 << ", Calc: " << stddev1
            << std::endl;
      success = false;
   }

   // Test using a test vector with expected values from excel
   Statistics statsTest2;
   constexpr const int TEST_ELEMENTS = 9999;
   constexpr const double AVG_EXPECTED2 = 4999.5;
   constexpr const double STD_DEV_EXPECTED2 = 2886.751332;
   for (int i = 0; i <= TEST_ELEMENTS; i++)
   {
      statsTest2.addNumber(i);
   }

   double avg2 = statsTest2.getAverage();
   if (!Utility::isEqual(avg2, AVG_EXPECTED2))
   {
      std::cerr << "Avg failure: Expected: " << AVG_EXPECTED2 << ", Calc: " << avg2 << std::endl;
      success = false;
   }

   double stddev2 = statsTest2.getStdDev();
   if (!Utility::isEqual(stddev2, STD_DEV_EXPECTED2))
   {
      std::cerr << "StdDev failure: Expected: " << STD_DEV_EXPECTED2 << ", Calc: " << stddev2
            << std::endl;
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
