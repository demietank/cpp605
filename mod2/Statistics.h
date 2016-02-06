/*
 * Statistics.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Chris
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

/**
 * @brief
 */
class Statistics
{
public:
   /**
    * @brief Constructs an empty sequence.
    */
   Statistics();

   /**
    * @brief Destructors the sequence.
    */
   ~Statistics();

   /**
    * @brief Adds an integer to the sequence.
    *
    * @param[in] num Integer to add to the sequence.
    *
    * @return True if the integer was successfully added.
    */
   bool addNumber(const int num);

   /**
    * @brief Returns the average of the sequence.
    */
   double getAverage() const;

   /**
    * @brief Returns the standard deviation of the sequence.
    */
   double getStdDev() const;

private:
   /**
    * @brief Summation of the elements in the sequence.
    */
   int mTotal;

   /**
    * @Brief Number of elements in the sequence.
    */
   unsigned int mNumElements;

};

#endif /* STATISTICS_H_ */
