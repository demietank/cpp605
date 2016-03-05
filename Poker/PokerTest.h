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

   /// Tests logic for four of a kind.
   static bool fourOfKindTest();

   /// Tests logic for a full house.
   static bool fullHouseTest();

   /// Tests logic for a flush.
   static bool flushTest();

   /// Tests logic for a straight.
   static bool straightTest();

   /// Tests logic for three of a kind.
   static bool threeOfKindTest();

   /// Tests logic for two pair.
   static bool twoPairTest();

   /// Tests logic for one pair.
   static bool onePairTest();

   /// Tests logic for high card.
   static bool highCardTest();
};

} /* namespace PokerGame */

#endif /* POKERTEST_H_ */
