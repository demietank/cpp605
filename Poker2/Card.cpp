/*
 * Card.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include "Card.h"

namespace pokergame
{

Card::Card(const Rank rank,
           const Suit suit) :
      mRank(rank),
      mSuit(suit)
{
}

std::ostream& operator<<(std::ostream& out,
                         const Suit& suit)
{
   const char * s = 0;
   switch (suit)
   {
   case Suit::SPADE:
      s = "S";
      break;
   case Suit::CLUB:
      s = "C";
      break;
   case Suit::DIAMOND:
      s = "D";
      break;
   case Suit::HEART:
      s = "H";
      break;
   default:
      s = "";
      break;
   }

   return out << s;
}

std::ostream& operator<<(std::ostream& out,
                         const Rank& rank)
{
   const char * s = 0;
   switch (rank)
   {
   case Rank::TWO:
      s = " 2";
      break;
   case Rank::THREE:
      s = " 3";
      break;
   case Rank::FOUR:
      s = " 4";
      break;
   case Rank::FIVE:
      s = " 5";
      break;
   case Rank::SIX:
      s = " 6";
      break;
   case Rank::SEVEN:
      s = " 7";
      break;
   case Rank::EIGHT:
      s = " 8";
      break;
   case Rank::NINE:
      s = " 9";
      break;
   case Rank::TEN:
      s = "10";
      break;
   case Rank::JACK:
      s = " J";
      break;
   case Rank::QUEEN:
      s = " Q";
      break;
   case Rank::KING:
      s = " K";
      break;
   case Rank::ACE:
      s = " A";
      break;
   default:
      s = "";
      break;
   }

   return out << s;
}

std::ostream& operator<<(std::ostream& out,
                         const Card& card)
{
   out << card.mRank << card.mSuit;
   return out;
}

} // end pokergame::
