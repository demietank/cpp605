/*
 * ExpressionTest.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include <iostream>

#include "Node.h"
#include "Constant.h"
#include "Expression.h"
#include "Variable.h"
#include "ExpressionTest.h"

namespace expressions
{

bool ExpressionTest::test()
{
   bool ret = true;

   Constant c { 5.5 };
   Variable x { "X" };
   Add nAdd = Add(std::make_unique<Constant>(7.3), std::make_unique<Variable>("Z"));

   std::cout << c << std::endl << x << std::endl;

   return ret;
}

} /* namespace expressions */

/**
 * @brief Entry point to the expression tree test.
 */
int main()
{
   using namespace expressions;

   if (!ExpressionTest::test())
   {
      std::cout << "Expression tree test failed" << std::endl;
   }
   else
   {
      std::cout << "Expression tree test passes" << std::endl;
   }

   return 0;
}
