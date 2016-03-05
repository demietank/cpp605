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

/// A class that encapsulates a poker game.
class PokerGame
{
public:
   /// Create a poker game between two players.
   PokerGame(const Hand& hand1, const Hand& hand2);

   /// Returns the winning hand. If the game is a tie this returns a winning hand.
   Hand getWinner() const { return mWinner; }

   /// Whether the game has a winning hand.
   /// If false is returned the game is considered a tie.
   bool hasWinner() const { return mHasWinner; }

private:
   /// Outputs an ASCII representation of the poker game.
   friend std::ostream& operator<<(std::ostream& out,
                                   const PokerGame& game);

   /// Whether the game has a winner.
   bool mHasWinner;

   /// The winning hand.
   Hand mWinner;

   /// The losing hand.
   Hand mLoser;
};

/// Outputs an ASCII representation of the poker game indicating its results.
std::ostream& operator<<(std::ostream& out,
                         const PokerGame& game);

} // end PokerGame::

#endif /* POKERGAME_H_ */
