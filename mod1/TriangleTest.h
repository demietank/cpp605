/*
 * TriangleTest.h
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#ifndef TRIANGLETEST_H_
#define TRIANGLETEST_H_

#include <vector>

#include "Triangle.h"

/**
 * @brief Triangle test sled to test the geometric calculations.
 *
 * @details
 *    Verifies the calculations of equilateral, isosceles, and scalene triangles.
 */
class TriangleTest
{
public:
   /**
    * @brief Add a triangle and its expected results to the test sled.
    */
   void addTriangle(const Triangle& triangle,
                    const bool isEquilateral,
                    const bool isIsosceles,
                    const bool isScalene);

   /**
    * @brief Test all triangles in the test sled to verify their qualities against expected results.
    *
    * @return Indication of whether the logic tests passed for all members of the test sled.
    */
   bool runTest() const;

private:
   /**
    * @brief Element of the test sled containing a triangle and expected results.
    */
   class TestVector
   {
   public:
      TestVector(const Triangle& triangle,
                 const bool isEquilateral,
                 const bool isIsosceles,
                 const bool isScalene);

      const Triangle& triangle;
      const bool isEquilateral;
      const bool isIsosceles;
      const bool isScalene;
   };

   void testTriangle(Triangle& triangle) const;

   std::vector<TestVector> trianglesToTest;
};

#endif /* TRIANGLETEST_H_ */
