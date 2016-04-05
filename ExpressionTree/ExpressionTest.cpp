/*
 * ExpressionTest.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include <iostream>
#include <map>
#include <string>

#include "Constant.h"
#include "Expression.h"
#include "Node.h"
#include "Tree.h"
#include "Variable.h"
#include "ExpressionTest.h"

namespace expressions
{

bool ExpressionTest::test()
{
   bool ret = true;

   const std::string X { "X" };
   const std::string Y { "Y" };
   const std::string Z { "Z" };
   VarMap vMap;

   // print miscellaneous combinations
   Constant c { 5.5 };
   Variable x = { X, vMap };
   std::cout << c << std::endl << x << std::endl;

   Add nAdd = Add(make_unique<Constant>(7.3), make_unique<Variable>("A", vMap));
   Sub nSub = Sub(make_unique<Constant>(7.4), make_unique<Variable>("G", vMap));
   Mul nMul = Mul(make_unique<Constant>(7.5), make_unique<Variable>("J", vMap));
   Div nDiv = Div(make_unique<Constant>(7.6), make_unique<Variable>("Ki", vMap));
   std::cout << nAdd << std::endl
            << nSub << std::endl
            << nMul << std::endl
            << nDiv << std::endl;

   // set the variables
   vMap[X] = 2;
   vMap[Y] = 3;
   vMap[Z] = 5;

   // print and evaluate project tree #1
   Tree t1 {
      make_unique<Add>(
            make_unique<Mul>(make_unique<Constant>(2.3), make_unique<Variable>(X, vMap)),
            make_unique<Mul>(make_unique<Variable>(Y, vMap),
                  make_unique<Sub>(make_unique<Variable>(Z, vMap), make_unique<Variable>(X, vMap)))) };
   std::cout << std::endl << t1 << std::endl;
   try
   {
      const auto t1Val = t1.evaluate();
      std::cout << "t1 evaluates to: " << t1Val << std::endl;
   }
   catch (...)
   {
      std::cerr << "exception caught evaluating t1" << std::endl;
      ret = false;
   }

   //print and evaluate the derivative of tree #1
   Tree dt = t1.derivative("X");
   std::cout << std::endl << dt << std::endl;
   try
   {
      const auto dtVal = dt.evaluate();
      std::cout << "dt evaluates to: " << dtVal << std::endl;
   }
   catch (...)
   {
      std::cerr << "exception caught evaluating dt" << std::endl;
      ret = false;
   }

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
