/*
 * Deck.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include "Deck.h"

namespace pokergame
{

Deck::Deck() :
      mDeck {
   {Rank::TWO, Suit::SPADE}, {Rank::TWO, Suit::CLUB}, {Rank::TWO, Suit::DIAMOND}, {Rank::TWO, Suit::HEART},
   {Rank::THREE, Suit::SPADE}, {Rank::THREE, Suit::CLUB}, {Rank::THREE, Suit::DIAMOND}, {Rank::THREE, Suit::HEART},
   {Rank::FOUR, Suit::SPADE}, {Rank::FOUR, Suit::CLUB}, {Rank::FOUR, Suit::DIAMOND}, {Rank::FOUR, Suit::HEART},
   {Rank::FIVE, Suit::SPADE}, {Rank::FIVE, Suit::CLUB}, {Rank::FIVE, Suit::DIAMOND}, {Rank::FIVE, Suit::HEART},
   {Rank::SIX, Suit::SPADE}, {Rank::SIX, Suit::CLUB}, {Rank::SIX, Suit::DIAMOND}, {Rank::SIX, Suit::HEART},
   {Rank::SEVEN, Suit::SPADE}, {Rank::SEVEN, Suit::CLUB}, {Rank::SEVEN, Suit::DIAMOND}, {Rank::SEVEN, Suit::HEART},
   {Rank::EIGHT, Suit::SPADE}, {Rank::EIGHT, Suit::CLUB}, {Rank::EIGHT, Suit::DIAMOND}, {Rank::EIGHT, Suit::HEART},
   {Rank::NINE, Suit::SPADE}, {Rank::NINE, Suit::CLUB}, {Rank::NINE, Suit::DIAMOND}, {Rank::NINE, Suit::HEART},
   {Rank::TEN, Suit::SPADE}, {Rank::TEN, Suit::CLUB}, {Rank::TEN, Suit::DIAMOND}, {Rank::TEN, Suit::HEART},
   {Rank::JACK, Suit::SPADE}, {Rank::JACK, Suit::CLUB}, {Rank::JACK, Suit::DIAMOND}, {Rank::JACK, Suit::HEART},
   {Rank::QUEEN, Suit::SPADE}, {Rank::QUEEN, Suit::CLUB}, {Rank::QUEEN, Suit::DIAMOND}, {Rank::QUEEN, Suit::HEART},
   {Rank::KING, Suit::SPADE}, {Rank::KING, Suit::CLUB}, {Rank::KING, Suit::DIAMOND}, {Rank::KING, Suit::HEART}}
{
}

Deck::~Deck()
{
}

Card Deck::getCard()
{
   auto card = mDeck.back();
   mDeck.pop_back();
   return card;
}

void Deck::shuffle()
{

}

} /* namespace pokergame */
