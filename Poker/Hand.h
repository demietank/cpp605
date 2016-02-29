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

class Hand
{
public:
   /// Constructs a full poker hand of cards.
   Hand(const Card& card1,
        const Card& card2,
        const Card& card3,
        const Card& card4,
        const Card& card5);

   bool isStraightFlush() const;
   bool isFourOfKind() const;
   bool isFullHouse() const;
   bool isFlush() const;
   bool isStraight() const;
   bool isThreeOfKind() const;
   bool isTwoPair() const;
   bool isOnePair() const;
   Card getHighCard() const;

private:
   /// Outputs an ASCII representation of the hand.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Hand& hand);

   /// The set of playing cards in the hand.
   std::array<Card, HAND_SIZE> mCards;
};

/// Outputs an ASCII representation of the hand.
std::ostream& operator<<(std::ostream& out,
                         const Hand& hand);

} // end PokerGame::

#endif /* HAND_H_ */
