/*
 * ProbabilityTest.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: Chris
 */

#include <iostream>

#include "EventProbability.h"
#include "ProbabilityTest.h"

namespace probability
{

bool ProbabilityTest::aAndBTest()
{
   constexpr const double A_IN   = 0.2;
   constexpr const double B_IN   = 0.2;
   constexpr const double AB_EXP = 0.04;

   if ((EventProbability(A_IN) & EventProbability(B_IN)) != EventProbability(AB_EXP))
   {
      return false;
   }

   return true;
}

bool ProbabilityTest::aOrBTest()
{
   constexpr const double A_IN   = 0.2;
   constexpr const double B_IN   = 0.2;
   constexpr const double AB_EXP = 0.04;

   if ((EventProbability(A_IN) & EventProbability(B_IN)) != EventProbability(AB_EXP))
   {
      return false;
   }

   return true;
}

bool ProbabilityTest::aXOrBTest()
{
   return true;
}

bool ProbabilityTest::aNotBTest()
{
   return true;
}

bool ProbabilityTest::notATest()
{
   return true;
}

bool ProbabilityTest::test()
{
   bool ret = true;

   if (!aAndBTest())
   {
      std::cout << "aAndBTest test failed" << std::endl;
      ret = false;
   }

   if (!aOrBTest())
   {
      std::cout << "aOrBTest test failed" << std::endl;
      ret = false;
   }

   if (!aXOrBTest())
   {
      std::cout << "aXOrBTest test failed" << std::endl;
      ret = false;
   }

   if (!aNotBTest())
   {
      std::cout << "aNotBTest test failed" << std::endl;
      ret = false;
   }

   if (!notATest())
   {
      std::cout << "notATest test failed" << std::endl;
      ret = false;
   }

   return ret;
}

} /* namespace probability */

/**
 * @brief Entry point to the probability test.
 */
int main()
{
   using namespace probability;

   if (!ProbabilityTest::test())
   {
      std::cout << "Probability test failed" << std::endl;
   }
   else
   {
      std::cout << "Probability test passes" << std::endl;
   }

   return 0;
}
