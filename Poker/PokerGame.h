/*
 * PokerGame.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#ifndef POKERGAME_H_
#define POKERGAME_H_

#include <ostream>
#include <vector>

#include "Card.h"
#include "Hand.h"

namespace PokerGame
{

class PokerGame
{
public:
   /// Add a hand to the game.
   void addHand(const Hand& hand);

   /// Reset the game to an empty state.
   void reset();

private:
   /// Outputs an ASCII representation of the poker game.
   friend std::ostream& operator<<(std::ostream& out,
                                   const PokerGame& game);

   /// The set of playing cards in the hand.
   std::vector<Hand> mHands;
};

/// Outputs an ASCII representation of the poker game.
std::ostream& operator<<(std::ostream& out,
                         const PokerGame& game);

} // end PokerGame::

#endif /* POKERGAME_H_ */
