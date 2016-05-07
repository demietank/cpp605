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
      s = " 10";
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

bool getCardFromStr(const std::string& str, Card& card)
{
   bool foundSuit = true;
   bool foundRank = true;
   Suit suit;
   Rank rank;

   // Check for valid suit
   if (str.find("S") != std::string::npos)
   {
      suit = Suit::SPADE;
   }
   else if (str.find("C") != std::string::npos)
   {
      suit = Suit::CLUB;
   }
   else if (str.find("D") != std::string::npos)
   {
      suit = Suit::DIAMOND;
   }
   else if (str.find("H") != std::string::npos)
   {
      suit = Suit::HEART;
   }
   else
   {
      foundSuit = false;
   }

   // Check for valid rank
   if (str.find("2") != std::string::npos)
   {
      rank = Rank::TWO;
   }
   else if (str.find("3") != std::string::npos)
   {
      rank = Rank::THREE;
   }
   else if (str.find("4") != std::string::npos)
   {
      rank = Rank::FOUR;
   }
   else if (str.find("5") != std::string::npos)
   {
      rank = Rank::FIVE;
   }
   else if (str.find("6") != std::string::npos)
   {
      rank = Rank::SIX;
   }
   else if (str.find("7") != std::string::npos)
   {
      rank = Rank::SEVEN;
   }
   else if (str.find("8") != std::string::npos)
   {
      rank = Rank::EIGHT;
   }
   else if (str.find("9") != std::string::npos)
   {
      rank = Rank::NINE;
   }
   else if (str.find("10") != std::string::npos)
   {
      rank = Rank::TEN;
   }
   else if (str.find("J") != std::string::npos)
   {
      rank = Rank::JACK;
   }
   else if (str.find("Q") != std::string::npos)
   {
      rank = Rank::QUEEN;
   }
   else if (str.find("K") != std::string::npos)
   {
      rank = Rank::KING;
   }
   else if (str.find("A") != std::string::npos)
   {
      rank = Rank::ACE;
   }
   else
   {
      foundRank = false;
   }

   if (foundSuit && foundRank)
   {
      card = {rank, suit};
   }

   return (foundSuit && foundRank);
}

} // end pokergame::
