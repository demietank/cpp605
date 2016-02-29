/*
 * PokerGame.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include "PokerGame.h"

namespace PokerGame
{

void PokerGame::addHand(const Hand& hand)
{
   mHands.emplace_back(hand);
}

void PokerGame::reset()
{
   mHands.clear();
}

std::ostream& operator<<(std::ostream& out,
                         const PokerGame& game)
{
   constexpr const char * GAME_BORDER = "---------------";

   out << GAME_BORDER << std::endl;
   for (const auto& hand : game.mHands)
   {
      out << hand << std::endl;
   }
   out << GAME_BORDER << std::endl;

   return out;
}

} // end PokerGame::
