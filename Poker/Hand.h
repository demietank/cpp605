/*
 * Hand.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#ifndef HAND_H_
#define HAND_H_

#include <array>
#include <ostream>

#include "Card.h"

namespace PokerGame
{

/// Number of cards in a hand.
constexpr const unsigned int HAND_SIZE = 5;

enum class HandComparrison
{
   DEFEATS,
   TIES,
   LOSES
};

/// A class that encapsulates a full poker hand.
class Hand
{
public:
   /// Constructs a full poker hand of cards.
   Hand(const Card& card1,
        const Card& card2,
        const Card& card3,
        const Card& card4,
        const Card& card5);

   /// Determines whether the hand is a straight flush and returns the high card rank.
   bool isStraightFlush(Rank& winningRank) const;

   /// Determines whether the hand has a set of 4 cards, and returns the pair and loser ranks.
   bool isFourOfKind(Rank& winningRank,
                     std::vector<Rank>& losingRank) const;

   /// Determines whether the hand has unique sets of 3 and 2 cards, and returns the pair and loser ranks.
   bool isFullHouse(Rank& winningRank1,
                    Rank& winningRank2,
                    std::vector<Rank>& losingRank) const;

   /// Determines whether the hand is a flush.
   bool isFlush() const;

   /// Determines whether the hand is a straight and returns the high card rank.
   bool isStraight(Rank& winningRank) const;

   /// Determines whether the hand has a set of 3 cards, and returns the pair and loser ranks.
   bool isThreeOfKind(Rank& winningRank,
                      std::vector<Rank>& losingRank) const;

   /// Determines whether the hand has 2 sets of 2 cards, and returns the pair and loser ranks.
   bool isTwoPair(Rank& winningRank1,
                  Rank& winningRank2,
                  std::vector<Rank>& losingRank) const;

   /// Determines whether the hand has a set of 2 cards, and returns the pair and loser ranks.
   bool isOnePair(Rank& winningRank,
                  std::vector<Rank>& losingRank) const;

   /// Determines the winner between two hands, if any.
   HandComparrison getWinner(const Hand& other) const;

   /// Determines whether two hands have exactly the same cards.
   bool operator==(const Hand& other) const;
   bool operator!=(const Hand& other) const;

private:
   /// Outputs an ASCII representation of the hand.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Hand& hand);

   /// Determines whether the hand has a variably sized set of matching cards, and returns the pair and loser ranks.
   bool hasPair(const unsigned int numInPair,
                Rank& winningRank,
                std::vector<Rank>& losingRank) const;

   /// Determines the winner between two sets of cards based on high card.
   template<typename Iterator>
   HandComparrison getWinnerHighCard(Iterator begin,
                                     Iterator end,
                                     Iterator beginOther,
                                     Iterator endOther) const
   {
      HandComparrison outcome = HandComparrison::TIES;

      // This expects cards to be pre-sorted based on rank
      for (; (begin != end) && (beginOther != endOther); ++begin, ++beginOther)
      {
         if (*begin > *beginOther)
         {
            outcome = HandComparrison::DEFEATS;
            break;
         }
         else if (*begin < *beginOther)
         {
            outcome = HandComparrison::LOSES;
            break;
         }
      }

      return outcome;
   }

   /// The set of playing cards in the hand.
   /// This is sorted in descending order such that the best card is first.
   std::array<Card, HAND_SIZE> mCards;
};

/// Outputs an ASCII representation of the hand.
std::ostream& operator<<(std::ostream& out,
                         const Hand& hand);

} // end PokerGame::

#endif /* HAND_H_ */
