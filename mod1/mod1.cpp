/*
 * mod1.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#include <iostream>

#include "Triangle.h"
#include "TriangleTest.h"

/**
 * @brief Entry point to module 1 test.
 */
int main()
{
   bool success;
   TriangleTest testSled;
   std::cout << "Running module 1 test..." << std::endl;

   // load the sled with triangles of known qualities

   // invalid - should cause assert if included
   //testSled.addTriangle(Triangle(0, 1, 1));
   //testSled.addTriangle(Triangle(1, 0, 1));
   //testSled.addTriangle(Triangle(1, 1, 0));

   // equilateral, isosceles
   testSled.addTriangle(Triangle(1, 1, 1), true, true, false);
   testSled.addTriangle(Triangle(3, 3, 3), true, true, false);

   // isosceles
   testSled.addTriangle(Triangle(1, 1, 2), false, true, false);
   testSled.addTriangle(Triangle(1, 2, 1), false, true, false);
   testSled.addTriangle(Triangle(2, 1, 1), false, true, false);

   // scalene
   testSled.addTriangle(Triangle(1, 2, 3), false, false, true);
   testSled.addTriangle(Triangle(2, 5, 7), false, false, true);

   success = testSled.runTest();
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
