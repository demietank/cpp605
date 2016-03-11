/*
 * ProbabilityTest.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: Chris
 */

#include <iostream>
#include <vector>

#include "EventProbability.h"
#include "ProbabilityTest.h"

namespace probability
{

bool ProbabilityTest::aAndBTest()
{
   std::vector<double> A_IN = { 0.2, 0.2, 0.8 };
   std::vector<double> B_IN = { 0.2, 0.7, 0.3 };
   std::vector<double> AB_EXP = { 0.04, 0.14, 0.24 };

   auto ain = A_IN.begin();
   auto bin = B_IN.begin();
   auto ab_itr = AB_EXP.begin();
   for (; (ain != A_IN.end()) && (bin != B_IN.end()) && ab_itr != AB_EXP.end();
         ain++, bin++, ab_itr++)
   {
      EventProbability ab_exp = *ab_itr; // demonstrate assignment
      if ((EventProbability(*ain) & EventProbability(*bin)) != ab_exp)
      {
         return false;
      }
   }

   return true;
}

bool ProbabilityTest::aOrBTest()
{
   std::vector<double> A_IN = { 0.2, 0.2, 0.8 };
   std::vector<double> B_IN = { 0.2, 0.7, 0.3 };
   std::vector<double> AB_EXP = { 0.36, 0.76, 0.86 };

   auto ain = A_IN.begin();
   auto bin = B_IN.begin();
   auto ab_itr = AB_EXP.begin();
   for (; (ain != A_IN.end()) && (bin != B_IN.end()) && ab_itr != AB_EXP.end();
         ain++, bin++, ab_itr++)
   {
      EventProbability ab_exp = *ab_itr; // demonstrate assignment
      if ((EventProbability(*ain) | EventProbability(*bin)) != ab_exp)
      {
         return false;
      }
   }

   return true;
}

bool ProbabilityTest::aXOrBTest()
{
   std::vector<double> A_IN = { 0.2, 0.2, 0.8 };
   std::vector<double> B_IN = { 0.2, 0.7, 0.3 };
   std::vector<double> AB_EXP = { 0.32, 0.62, 0.62 };

   auto ain = A_IN.begin();
   auto bin = B_IN.begin();
   auto ab_itr = AB_EXP.begin();
   for (; (ain != A_IN.end()) && (bin != B_IN.end()) && ab_itr != AB_EXP.end();
         ain++, bin++, ab_itr++)
   {
      EventProbability ab_exp = *ab_itr; // demonstrate assignment
      if ((EventProbability(*ain) ^ EventProbability(*bin)) != ab_exp)
      {
         return false;
      }
   }

   return true;
}

bool ProbabilityTest::aNotBTest()
{
   std::vector<double> A_IN = { 0.2, 0.2, 0.8 };
   std::vector<double> B_IN = { 0.2, 0.7, 0.3 };
   std::vector<double> AB_EXP = { 0.16, 0.06, 0.56 };

   auto ain = A_IN.begin();
   auto bin = B_IN.begin();
   auto ab_itr = AB_EXP.begin();
   for (; (ain != A_IN.end()) && (bin != B_IN.end()) && ab_itr != AB_EXP.end();
         ain++, bin++, ab_itr++)
   {
      EventProbability ab_exp = *ab_itr; // demonstrate assignment
      if ((EventProbability(*ain) - EventProbability(*bin)) != ab_exp)
      {
         return false;
      }
   }

   return true;
}

bool ProbabilityTest::notATest()
{
   std::vector<double> A_IN = { 0.2, 0.2, 0.8 };
   std::vector<double> NOTA_EXP = { 0.8, 0.8, 0.2 };

   auto ain = A_IN.begin();
   auto nota_itr = NOTA_EXP.begin();
   for (; (ain != A_IN.end()) && nota_itr != NOTA_EXP.end();
         ain++, nota_itr++)
   {
      EventProbability nota_exp = *nota_itr; // demonstrate assignment
      if (~EventProbability(*ain) != nota_exp)
      {
         return false;
      }
   }

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
