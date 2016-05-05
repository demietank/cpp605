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

class Deck
{
public:
   Deck();
   virtual ~Deck();

   void addCard(const Card card);
   Card getCard();
   void shuffle();

private:
   CardCont mDeck;
};

} /* namespace pokergame */

#endif /* DECK_H_ */
