/*
 * PokerGame.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include <algorithm>

#include "PokerGame.h"

namespace PokerGame
{

/// Create a poker game between two players.
PokerGame::PokerGame(const Hand& hand1, const Hand& hand2) :
      mHasWinner(false),
      mWinner(hand1),
      mLoser(hand2)
{
   // determine the winning hand
   auto outcome = mWinner.getWinner(mLoser);
   if (outcome != HandComparrison::TIES)
   {
      mHasWinner = true;
      if (outcome == HandComparrison::LOSES)
      {
         std::swap(mWinner, mLoser);
      }
   }
}

std::ostream& operator<<(std::ostream& out,
                         const PokerGame& game)
{
   constexpr const char * GAME_BORDER = "---------------";

   out << GAME_BORDER << std::endl;
   out << game.mWinner << std::endl;

   if (game.hasWinner())
   {
      out << "Defeats" << std::endl;
   }
   else
   {
      out << "Ties" << std::endl;
   }

   out << game.mLoser << std::endl;
   out << GAME_BORDER << std::endl;

   return out;
}

} // end PokerGame::
