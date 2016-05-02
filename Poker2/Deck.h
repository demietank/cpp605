/*
 * Deck.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>

#include "Card.h"

namespace pokergame
{

class Deck
{
public:
   Deck();
   virtual ~Deck();

   Card getCard();
   void shuffle();

private:
   std::vector<Card> mDeck;
};

} /* namespace pokergame */

#endif /* DECK_H_ */
