/*
 * Hand.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include <algorithm>

#include "Hand.h"

namespace pokergame
{

Hand::Hand(const Card& card1,
           const Card& card2,
           const Card& card3,
           const Card& card4,
           const Card& card5) :
      mCards( { card1, card2, card3, card4, card5 })
{
   // sort in descending order such that the best card is first
   std::sort(mCards.rbegin(), mCards.rend());
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

bool Hand::isStraightFlush(Rank& winningRank) const
{
   bool ret = false;

   if (isFlush())
   {
      ret = isStraight(winningRank);
   }

   return ret;
}

bool Hand::isFourOfKind(Rank& winningRank,
                        std::vector<Rank>& losingRank) const
{
   constexpr const unsigned int MIN_MATCH = 4;
   return hasPair(MIN_MATCH, winningRank, losingRank);
}

bool Hand::isFullHouse(Rank& winningRank1,
                       Rank& winningRank2,
                       std::vector<Rank>& losingRank) const
{
   constexpr const unsigned int MATCH2 = 2;
   constexpr const unsigned int MATCH3 = 3;
   bool twoPair = false;
   bool threePair = false;

   // an array of matches, indexed by rank
   std::array<unsigned int, static_cast<unsigned int>(Rank::ACE) + 1> matches { 0 };
   for (const auto& card : mCards)
   {
      matches.at(static_cast<unsigned int>(card.getRank()))++;
   }

   for (auto it = matches.crbegin(); it != matches.crend(); ++it)
   {
      if (*it == MATCH3)
      {
         // get the rank based on array offset - get highest pair first
         winningRank1 = static_cast<Rank>(std::distance(it, matches.crbegin()));
         threePair = true;
      }
      else if (*it == MATCH2)
      {
         // get the rank based on array offset - get highest pair first
         winningRank2 = static_cast<Rank>(std::distance(it, matches.crbegin()));
         twoPair = true;
      }
      else if (*it > 0)
      {
         unsigned int numLosers = *it;
         do
         {
            losingRank.emplace_back(static_cast<Rank>(std::distance(it, matches.crbegin())));
            numLosers--;
         } while (numLosers > 0);
      }
   }

   return (twoPair && threePair);
}

bool Hand::isFlush() const
{
   bool ret = true;

   Suit firstSuit = mCards.front().getSuit();
   for (auto it = mCards.cbegin() + 1; it != mCards.cend(); ++it)
   {
      if (it->getSuit() != firstSuit)
      {
         ret = false;
         break;
      }
   }

   return ret;
}

bool Hand::isStraight(Rank& winningRank) const
{
   bool ret = true;

   // rotate a local copy of the hand based on Ace high/low
   // assume mCards is already sorted Ace high
   auto cards = mCards;
   if ((cards.begin()->getRank() == Rank::ACE) && (cards.end()->getRank() == Rank::TWO))
   {
      std::rotate(cards.begin(), cards.end(), cards.begin() + 1);
   }

   Rank lastRank = cards.front().getRank();
   for (auto it = cards.cbegin() + 1; it != cards.cend(); ++it)
   {
      // compare current rank against a decremented value of the previously returned rank
      if (it->getRank() != static_cast<Rank>(static_cast<unsigned int>(lastRank)-1))
      {
         ret = false;
         break;
      }
      else
      {
         lastRank = it->getRank();
      }
   }

   if (ret)
   {
      winningRank = cards.front().getRank();
   }

   return ret;
}

bool Hand::isThreeOfKind(Rank& winningRank,
                         std::vector<Rank>& losingRank) const
{
   constexpr const unsigned int MIN_MATCH = 3;
   return hasPair(MIN_MATCH, winningRank, losingRank);
}

bool Hand::isTwoPair(Rank& winningRank1,
                     Rank& winningRank2,
                     std::vector<Rank>& losingRank) const
{
   constexpr const unsigned int MIN_MATCH = 2;
   bool ret = false;
   bool firstPair = false;

   // an array of matches, indexed by rank
   std::array<unsigned int, static_cast<unsigned int>(Rank::ACE) + 1> matches { 0 };
   for (const auto& card : mCards)
   {
      matches.at(static_cast<unsigned int>(card.getRank()))++;
   }

   for (auto it = matches.crbegin(); it != matches.crend(); ++it)
   {
      if (*it >= MIN_MATCH)
      {
         // get two unique pairs
         // get the rank based on array offset - get highest pair first
         if (!firstPair)
         {
            winningRank1 = static_cast<Rank>(std::distance(it, matches.crbegin()));
            firstPair = true;
         }
         else
         {
            winningRank2 = static_cast<Rank>(std::distance(it, matches.crbegin()));
            ret = true;
         }
      }
      else if (*it > 0)
      {
         unsigned int numLosers = *it;
         do
         {
            losingRank.emplace_back(static_cast<Rank>(std::distance(it, matches.crbegin())));
            numLosers--;
         } while (numLosers > 0);
      }
   }

   return ret;
}

bool Hand::isOnePair(Rank& winningRank,
                     std::vector<Rank>& losingRank) const
{
   constexpr const unsigned int MIN_MATCH = 2;
   return hasPair(MIN_MATCH, winningRank, losingRank);
}

bool Hand::hasPair(const unsigned int numInPair,
                   Rank& winningRank,
                   std::vector<Rank>& losingRank) const
{
   bool ret = false;

   // an array of matches, indexed by rank
   std::array<unsigned int, static_cast<unsigned int>(Rank::ACE) + 1> matches { 0 };
   for (const auto& card : mCards)
   {
      matches.at(static_cast<unsigned int>(card.getRank()))++;
   }

   for (auto it = matches.crbegin(); it != matches.crend(); ++it)
   {
      if (*it >= numInPair)
      {
         // get the rank based on array offset - get highest pair first
         winningRank = static_cast<Rank>(std::distance(it, matches.crbegin()));
         ret = true;
      }
      else if (*it > 0)
      {
         unsigned int numLosers = *it;
         do
         {
            losingRank.emplace_back(static_cast<Rank>(std::distance(it, matches.crbegin())));
            numLosers--;
         } while (numLosers > 0);
      }
   }

   return ret;
}

HandComparrison Hand::getWinner(const Hand& other) const
{
   HandComparrison outcome = HandComparrison::LOSES;
   Rank winningRank1;
   Rank winningRank2;
   std::vector<Rank> losingRank;
   Rank winningRankOther1;
   Rank winningRankOther2;
   std::vector<Rank> losingRankOther;

   if (isStraightFlush(winningRank1) || other.isStraightFlush(winningRankOther1))
   {
      if (isStraightFlush(winningRank1) && other.isStraightFlush(winningRankOther1))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            outcome = HandComparrison::TIES;
         }
      }
      else if (other.isStraightFlush(winningRankOther1))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isFourOfKind(winningRank1, losingRank))
   {
      if (other.isFourOfKind(winningRankOther1, losingRankOther))
      {
         // non-paired cards compared for winner
         outcome = getWinnerHighCard(losingRank.begin(), losingRank.end(), losingRankOther.begin(),
               losingRankOther.end());
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isFullHouse(winningRank1, winningRank2, losingRank) || other.isFullHouse(winningRankOther1, winningRankOther2, losingRankOther))
   {
      if (isFullHouse(winningRank1, winningRank2, losingRank) && other.isFullHouse(winningRankOther1, winningRankOther2, losingRankOther))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            if (winningRank2 > winningRankOther2)
            {
               outcome = HandComparrison::DEFEATS;
            }
            else if (winningRank2 == winningRankOther2)
            {
               // non-paired cards compared for winner
               outcome = getWinnerHighCard(losingRank.begin(), losingRank.end(),
                     losingRankOther.begin(), losingRankOther.end());
            }
         }
      }
      else if (other.isFullHouse(winningRankOther1, winningRankOther2, losingRankOther))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isFlush() || other.isFlush())
   {
      if (other.isFlush() && other.isFlush())
      {
         // Winner is determined by high card(s)
         outcome = getWinnerHighCard(mCards.begin(), mCards.end(), other.mCards.begin(),
               other.mCards.end());
      }
      else if (other.isFlush())
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isStraight(winningRank1) || other.isStraight(winningRankOther1))
   {
      if (isStraight(winningRank1) && other.isStraight(winningRankOther1))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            outcome = HandComparrison::TIES;
         }
      }
      else if (other.isStraight(winningRankOther1))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isThreeOfKind(winningRank1, losingRank) || other.isThreeOfKind(winningRankOther1, losingRankOther))
   {
      if (isThreeOfKind(winningRank1, losingRank) && other.isThreeOfKind(winningRankOther1, losingRankOther))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            // non-paired cards compared for winner
            outcome = getWinnerHighCard(losingRank.begin(), losingRank.end(),
                  losingRankOther.begin(), losingRankOther.end());
         }
      }
      else if (other.isThreeOfKind(winningRankOther1, losingRankOther))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isTwoPair(winningRank1, winningRank2, losingRank) || other.isTwoPair(winningRankOther1, winningRankOther2, losingRankOther))
   {
      if (isTwoPair(winningRank1, winningRank2, losingRank) && other.isTwoPair(winningRankOther1, winningRankOther2, losingRankOther))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            if (winningRank2 > winningRankOther2)
            {
               outcome = HandComparrison::DEFEATS;
            }
            else if (winningRank2 == winningRankOther2)
            {
               // non-paired cards compared for winner
               outcome = getWinnerHighCard(losingRank.begin(), losingRank.end(),
                     losingRankOther.begin(), losingRankOther.end());
            }
         }
      }
      else if (other.isTwoPair(winningRankOther1, winningRankOther2, losingRankOther))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else if (isOnePair(winningRank1, losingRank) || other.isOnePair(winningRankOther1, losingRankOther))
   {
      if (isOnePair(winningRank1, losingRank) && other.isOnePair(winningRankOther1, losingRankOther))
      {
         // arbitrate winner
         if (winningRank1 > winningRankOther1)
         {
            outcome = HandComparrison::DEFEATS;
         }
         else if (winningRank1 == winningRankOther1)
         {
            // non-paired cards compared for winner
            outcome = getWinnerHighCard(losingRank.begin(), losingRank.end(),
                  losingRankOther.begin(), losingRankOther.end());
         }
      }
      else if (other.isOnePair(winningRankOther1, losingRankOther))
      {
         outcome = HandComparrison::LOSES;
      }
      else
      {
         outcome = HandComparrison::DEFEATS;
      }
   }
   else
   {
      // Winner is determined by high card(s)
      outcome = getWinnerHighCard(mCards.begin(), mCards.end(), other.mCards.begin(),
            other.mCards.end());
   }

   return outcome;
}

bool Hand::operator==(const Hand& other) const
{
   return mCards == other.mCards;
}

bool Hand::operator!=(const Hand& other) const
{
   return mCards != other.mCards;
}

} // end pokergame::
