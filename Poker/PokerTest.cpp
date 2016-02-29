/*
 * PokerTest.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chris
 */

#include <iostream>

#include "PokerGame.h"
#include "PokerTest.h"

namespace PokerGame
{

void PokerTest::sortTest()
{
   std::cout << "Sort test" << std::endl;
   PokerGame game;

   Hand hand1(Card(Rank::JACK, Suit::HEART),
               Card(Rank::ACE, Suit::HEART),
               Card(Rank::FIVE, Suit::HEART),
               Card(Rank::SIX, Suit::HEART),
               Card(Rank::TWO, Suit::HEART));
   Hand hand2(Card(Rank::ACE, Suit::SPADE),
               Card(Rank::FIVE, Suit::SPADE),
               Card(Rank::FOUR, Suit::SPADE),
               Card(Rank::THREE, Suit::SPADE),
               Card(Rank::TWO, Suit::SPADE));
   game.addHand(hand1);
   game.addHand(hand2);
   std::cout << game << std::endl;
}

bool PokerTest::straightFlushTest()
{
   std::cout << "straight flush test" << std::endl;
   PokerGame game;

   Hand sflush1(Card(Rank::EIGHT, Suit::HEART),
               Card(Rank::SEVEN, Suit::HEART),
               Card(Rank::SIX, Suit::HEART),
               Card(Rank::FIVE, Suit::HEART),
               Card(Rank::FOUR, Suit::HEART));
   Hand sflush2(Card(Rank::SIX, Suit::SPADE),
               Card(Rank::FIVE, Suit::SPADE),
               Card(Rank::FOUR, Suit::SPADE),
               Card(Rank::THREE, Suit::SPADE),
               Card(Rank::TWO, Suit::SPADE));
   game.addHand(sflush1);
   game.addHand(sflush2);
   std::cout << game << std::endl;

   Hand flush3(Card(Rank::JACK, Suit::CLUB),
               Card(Rank::TEN, Suit::CLUB),
               Card(Rank::NINE, Suit::CLUB),
               Card(Rank::EIGHT, Suit::CLUB),
               Card(Rank::SEVEN, Suit::CLUB));
   Hand flush4(Card(Rank::JACK, Suit::DIAMOND),
               Card(Rank::TEN, Suit::DIAMOND),
               Card(Rank::NINE, Suit::DIAMOND),
               Card(Rank::EIGHT, Suit::DIAMOND),
               Card(Rank::SEVEN, Suit::DIAMOND));
   game.reset();
   game.addHand(flush3);
   game.addHand(flush4);
   std::cout << game << std::endl;

   return true;
}

bool PokerTest::test()
{
   bool ret = true;

   sortTest();

   if (!straightFlushTest())
   {
      std::cout << "straight flush test failed" << std::endl;
      ret = false;
   }

   return ret;
}

} /* namespace PokerGame */

/**
 * @brief Entry point to the poker game test.
 */
int main()
{
   using namespace PokerGame;

   if (!PokerTest::test())
   {
      std::cout << "Poker test failed" << std::endl;
   }

   return 0;
}
