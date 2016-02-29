/*
 * Hand.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include <algorithm>

#include "Hand.h"

namespace PokerGame
{

Hand::Hand(const Card& card1,
           const Card& card2,
           const Card& card3,
           const Card& card4,
           const Card& card5) :
      mCards( { card1, card2, card3, card4, card5 })
{
   std::sort(mCards.begin(), mCards.end(), Card::sortCards);
}

std::ostream& operator<<(std::ostream& out,
                         const Hand& hand)
{
   for (const auto& card : hand.mCards)
   {
      out << card << " ";
   }

   return out;
}

bool Hand::isStraightFlush() const
{
   bool ret = false;

   return ret;
}

bool Hand::isFourOfKind() const
{
   bool ret = false;

   return ret;
}

bool Hand::isFullHouse() const
{
   bool ret = false;

   return ret;
}

bool Hand::isFlush() const
{
   bool ret = false;

   for (const auto& it = mCards.cbegin()++; it != mCards.cend(); it++)
   {
      if (it != mCards.cbegin())
      {
         break;
      }
   }

   return ret;
}

bool Hand::isStraight() const
{
   bool ret = false;

   return ret;
}

bool Hand::isThreeOfKind() const
{
   bool ret = false;

   return ret;
}

bool Hand::isTwoPair() const
{
   bool ret = false;

   return ret;
}

bool Hand::isOnePair() const
{
   bool ret = false;

   return ret;
}

Card Hand::getHighCard() const
{
   return mCards.front();
}

} // end PokerGame::
