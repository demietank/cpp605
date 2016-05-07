/*
 * Deck.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef DECK_H_
#define DECK_H_

#include "common.h"
#include "Card.h"

namespace pokergame
{
// A deck of cards consisting of 52 unique playing cards.
class Deck
{
public:
   // Constructs a full, unshuffled, deck.
   Deck();
   virtual ~Deck();

   // Returns a card to the top of the deck.
   void addCard(const Card card);

   // Retrieves a card from the back of the deck.
   Card getCard();

   // Shuffles the deck (Fisher-Yates algorithm)
   void shuffle();

private:
   // Container holding the cards.
   CardCont mDeck;
};

} /* namespace pokergame */

#endif /* DECK_H_ */
