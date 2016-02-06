/*
 * Statistics.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Chris
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <vector>

/**
 * @brief A class that contains a variable number of integers and calculates statistics on the sequence.
 * @note This class is not thread safe.
 */
class Statistics
{
public:
   /**
    * @brief Constructs an empty sequence.
    */
   Statistics();

   /**
    * @brief Destructs the sequence.
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
    * @brief Container of numbers in this statistics sequence.
    */
   std::vector<int> mSequence;
};

#endif /* STATISTICS_H_ */
