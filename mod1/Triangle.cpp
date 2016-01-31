/*
 * Triangle.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#include <cassert>
#include <iostream>

#include "Triangle.h"

Triangle::Triangle(const unsigned int sideA, const unsigned int sideB, const unsigned int sideC) :
      sideA(sideA),
      sideB(sideB),
      sideC(sideC)
{
   // no fancy exception error handling in mod1
   assert(sideA > 0);
   assert(sideB > 0);
   assert(sideC > 0);
}

bool Triangle::isEquilateral() const
{
   return ((sideA == sideB) && (sideA == sideC));
}

bool Triangle::isIsosceles() const
{
   return ((sideA == sideB) || (sideA == sideC) || (sideB == sideC));
}

bool Triangle::isScalene() const
{
   return !isIsosceles();
}

void Triangle::print() const
{
   // output shape
   std::cout << "{ " << sideA << ", " << sideB << ", " << sideC << " }: ";

   // output qualities
   std::cout << "Equilateral = " << (isEquilateral() ? "Yes" : "No ") << "; "
         << "Isosceles = " << (isIsosceles() ? "Yes" : "No ") << "; "
         << "Scalene = " << (isScalene() ? "Yes" : "No ") << std::endl;
}
