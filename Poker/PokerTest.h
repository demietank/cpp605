/*
 * PokerTest.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#ifndef POKERTEST_H_
#define POKERTEST_H_

namespace PokerGame
{

/// Class that tests the PokerGame.
class PokerTest
{
public:
    /// Performs unit testing on the poker game.
   static bool test();

private:
   /// Tests logic for a hand sorting (visual verification).
   static void sortTest();

   /// Tests logic for a straight flush.
   static bool straightFlushTest();
};

} /* namespace PokerGame */

#endif /* POKERTEST_H_ */
