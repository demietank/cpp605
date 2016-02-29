/*
 * Card.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#ifndef CARD_H_
#define CARD_H_

#include <ostream>

namespace PokerGame
{

/// Card suit.
enum class Suit
{
   SPADE,
   CLUB,
   DIAMOND,
   HEART
};

/// Card rank.
enum class Rank
{
   TWO,
   THREE,
   FOUR,
   FIVE,
   SIX,
   SEVEN,
   EIGHT,
   NINE,
   TEN,
   JACK,
   QUEEN,
   KING,
   ACE
};

/// A class that encapsulates a playing card using the French card deck.
class Card
{
public:
   /// Constructs a card.
   Card(const Rank rank,
        const Suit suit);

   /// Returns the card rank.
   Rank getRank() const
   {
      return mRank;
   }

   /// Returns the card suit.
   Suit getSuit() const
   {
      return mSuit;
   }

   /// Used to order a hand of cards by rank.
   static bool sortCards(const Card& card1, const Card& card2) { return card1.getRank() > card2.getRank(); };

private:
   /// Outputs an ASCII representation of the card.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Card& card);

   /// Card rank
   Rank mRank;

   /// Card suit
   Suit mSuit;
};

/// Outputs an ASCII representation of the card suit.
std::ostream& operator<<(std::ostream& out,
                         const Suit& suit);

/// Outputs an ASCII representation of the card rank.
std::ostream& operator<<(std::ostream& out,
                         const Rank& rank);

/// Outputs an ASCII representation of the card.
std::ostream& operator<<(std::ostream& out,
                         const Card& card);

} // end PokerGame::

#endif /* CARD_H_ */
