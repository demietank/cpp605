/*
 * ProbabilityTest.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Chris
 */

#ifndef PROBABILITYTEST_H_
#define PROBABILITYTEST_H_

namespace probability
{

/// Class that tests EventProbabilty.
class ProbabilityTest
{
public:
   /// Performs unit testing on the probability of two independent events.
   static bool test();

private:
   /// Tests logic for the probability of A and B occurring.
   static bool aAndBTest();

   /// Tests logic for the probability of A or B occurring.
   static bool aOrBTest();

   /// Tests logic for the probability of A or B but not both occurring.
   static bool aXOrBTest();

   /// Tests logic for the probability of A but not B occurring.
   static bool aNotBTest();

   /// Tests logic for the probability of A not occurring.
   static bool notATest();
};

} /* namespace probability */

#endif /* PROBABILITYTEST_H_ */
