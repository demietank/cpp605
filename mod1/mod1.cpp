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
   //testSled.addTriangle(Triangle(0, 1, 1), false, false, true);
   //testSled.addTriangle(Triangle(1, 0, 1), false, false, true);
   //testSled.addTriangle(Triangle(1, 1, 0), false, false, true);
   //testSled.addTriangle(Triangle(1, 2, 20), false, false, true);
   //testSled.addTriangle(Triangle(2, 20, 1), false, false, true);
   //testSled.addTriangle(Triangle(20, 1, 2), false, false, true);

   // equilateral, isosceles
   testSled.addTriangle(Triangle(1, 1, 1), true, true, false);
   testSled.addTriangle(Triangle(3, 3, 3), true, true, false);

   // isosceles
   testSled.addTriangle(Triangle(5, 5, 6), false, true, false);
   testSled.addTriangle(Triangle(5, 6, 5), false, true, false);
   testSled.addTriangle(Triangle(6, 5, 5), false, true, false);

   // scalene
   testSled.addTriangle(Triangle(3, 4, 5), false, false, true);
   testSled.addTriangle(Triangle(2, 4, 3), false, false, true);

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
