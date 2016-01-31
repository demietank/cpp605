/*
 * triangle.h
 *
 *  Created on: Jan 31, 2016
 *      Author: Chris
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

/**
 * @brief A class representing the 3-sided geometrical shape, the triangle.
 */
class Triangle
{
public:
   /**
    * @brief Constructs a 3-sided geometrical shape, the triangle.
    *
    * @details All sides must be greater than zero.
    */
   Triangle(const unsigned int sideA, const unsigned int sideB, const unsigned int sideC);

   /**
    * @brief Forbid constructor.
    */
   Triangle() = delete;

   /**
    * @brief Whether the triangle is equilateral.
    *
    * @details An equilateral triangle has all sides equal.
    *
    * @return true if the triangle is equilateral.
    */
   bool isEquilateral() const;

   /**
    * @brief Whether the triangle is isosceles.
    *
    * @details An isosceles triangle has at least two sides equal.
    *
    * @return true if the triangle is isosceles.
    */
   bool isIsosceles() const;

   /**
    * @brief Whether the triangle is scalene.
    *
    * @details A scalene triangle has no sides equal.
    *
    * @return true if the triangle is scalene.
    */
   bool isScalene() const;

   /**
    * @brief Outputs the qualities and characteristics of the triangle.
    */
   void print() const;
private:
   const unsigned sideA;
   const unsigned sideB;
   const unsigned sideC;
};

#endif /* TRIANGLE_H_ */
