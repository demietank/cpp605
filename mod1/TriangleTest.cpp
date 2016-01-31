/*
 * TriangleTest.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#include <iostream>

#include "TriangleTest.h"

TriangleTest::TestVector::TestVector(const Triangle& triangle,
                                     const bool isEquilateral,
                                     const bool isIsosceles,
                                     const bool isScalene) :
      triangle(triangle),
      isEquilateral(isEquilateral),
      isIsosceles(isIsosceles),
      isScalene(isScalene)
{
}

void TriangleTest::addTriangle(const Triangle& triangle,
                               const bool isEquilateral,
                               const bool isIsosceles,
                               const bool isScalene)
{
   trianglesToTest.emplace_back(TestVector(triangle, isEquilateral, isIsosceles, isScalene));
}

bool TriangleTest::runTest() const
{
   bool success = true;
   for (const auto& triangleTest : trianglesToTest)
   {
      triangleTest.triangle.print();

      // test logic
      if (triangleTest.triangle.isEquilateral() != triangleTest.isEquilateral)
      {
         std::cout << "equilateral logic fault!!" << std::endl;
         success = false;
      }
      if (triangleTest.triangle.isIsosceles() != triangleTest.isIsosceles)
      {
         std::cout << "isosceles logic fault!!" << std::endl;
         success = false;
      }
      if (triangleTest.triangle.isScalene() != triangleTest.isScalene)
      {
         std::cout << "scalene logic fault!!" << std::endl;
         success = false;
      }
   }

   return success;
}
