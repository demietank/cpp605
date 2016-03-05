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
   std::cout << "sort test" << std::endl;

   Hand hand1(Card(Rank::JACK,   Suit::HEART),
              Card(Rank::ACE,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::TWO,    Suit::HEART));
   Hand hand2(Card(Rank::ACE,    Suit::SPADE),
              Card(Rank::FIVE,   Suit::SPADE),
              Card(Rank::FOUR,   Suit::SPADE),
              Card(Rank::THREE,  Suit::SPADE),
              Card(Rank::TWO,    Suit::SPADE));
   PokerGame game(hand1, hand2);
   std::cout << game;
}

bool PokerTest::straightFlushTest()
{
   bool status = true;
   std::cout << "straight flush test" << std::endl;

   Hand hand1(Card(Rank::EIGHT,  Suit::HEART),
              Card(Rank::SEVEN,  Suit::HEART),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FOUR,   Suit::HEART));
   Hand hand2(Card(Rank::SIX,    Suit::SPADE),
              Card(Rank::FIVE,   Suit::SPADE),
              Card(Rank::FOUR,   Suit::SPADE),
              Card(Rank::THREE,  Suit::SPADE),
              Card(Rank::TWO,    Suit::SPADE));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::JACK,   Suit::CLUB),
              Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::NINE,   Suit::CLUB),
              Card(Rank::EIGHT,  Suit::CLUB),
              Card(Rank::SEVEN,  Suit::CLUB));
   Hand hand4(Card(Rank::JACK,   Suit::DIAMOND),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::NINE,   Suit::DIAMOND),
              Card(Rank::EIGHT,  Suit::DIAMOND),
              Card(Rank::SEVEN,  Suit::DIAMOND));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      std::cerr << "hand failed to determine tie" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::fourOfKindTest()
{
   bool status = true;
   std::cout << "four of kind test" << std::endl;

   Hand hand1(Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::QUEEN,  Suit::DIAMOND));
   Hand hand2(Card(Rank::SIX,    Suit::DIAMOND),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::SIX,    Suit::SPADE),
              Card(Rank::SIX,    Suit::CLUB),
              Card(Rank::SEVEN,  Suit::SPADE));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::FIVE,   Suit::CLUB));
   Hand hand4(Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::TWO,    Suit::DIAMOND));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::fullHouseTest()
{
   bool status = true;
   std::cout << "full house test" << std::endl;

   Hand hand1(Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::FOUR,   Suit::SPADE),
              Card(Rank::FOUR,   Suit::DIAMOND));
   Hand hand2(Card(Rank::NINE,   Suit::HEART),
              Card(Rank::NINE,   Suit::CLUB),
              Card(Rank::NINE,   Suit::SPADE),
              Card(Rank::ACE,    Suit::HEART),
              Card(Rank::ACE,    Suit::CLUB));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::ACE,    Suit::SPADE),
              Card(Rank::ACE,    Suit::CLUB),
              Card(Rank::ACE,    Suit::HEART),
              Card(Rank::FOUR,   Suit::DIAMOND),
              Card(Rank::FOUR,   Suit::CLUB));
   Hand hand4(Card(Rank::ACE,    Suit::SPADE),
              Card(Rank::ACE,    Suit::HEART),
              Card(Rank::ACE,    Suit::DIAMOND),
              Card(Rank::THREE,  Suit::SPADE),
              Card(Rank::THREE,  Suit::DIAMOND));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::flushTest()
{
   bool status = true;
   std::cout << "flush test" << std::endl;

   Hand hand1(Card(Rank::ACE,    Suit::HEART),
              Card(Rank::QUEEN,  Suit::HEART),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::THREE,  Suit::HEART));
   Hand hand2(Card(Rank::KING,   Suit::SPADE),
              Card(Rank::QUEEN,  Suit::SPADE),
              Card(Rank::JACK,   Suit::SPADE),
              Card(Rank::NINE,   Suit::SPADE),
              Card(Rank::SIX,    Suit::SPADE));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::ACE,    Suit::DIAMOND),
              Card(Rank::KING,   Suit::DIAMOND),
              Card(Rank::SEVEN,  Suit::DIAMOND),
              Card(Rank::SIX,    Suit::DIAMOND),
              Card(Rank::TWO,    Suit::DIAMOND));
   Hand hand4(Card(Rank::ACE,    Suit::HEART),
              Card(Rank::QUEEN,  Suit::HEART),
              Card(Rank::TEN,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::THREE,  Suit::HEART));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::straightTest()
{
   bool status = true;
   std::cout << "straight test" << std::endl;

   Hand hand1(Card(Rank::EIGHT,  Suit::SPADE),
              Card(Rank::SEVEN,  Suit::SPADE),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FOUR,   Suit::SPADE));
   Hand hand2(Card(Rank::SIX,    Suit::DIAMOND),
              Card(Rank::FIVE,   Suit::SPADE),
              Card(Rank::FOUR,   Suit::DIAMOND),
              Card(Rank::THREE,  Suit::HEART),
              Card(Rank::TWO,    Suit::CLUB));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::EIGHT,  Suit::SPADE),
              Card(Rank::SEVEN,  Suit::SPADE),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FOUR,   Suit::SPADE));
   Hand hand4(Card(Rank::EIGHT,  Suit::HEART),
              Card(Rank::SEVEN,  Suit::DIAMOND),
              Card(Rank::SIX,    Suit::CLUB),
              Card(Rank::FIVE,   Suit::CLUB),
              Card(Rank::FOUR,   Suit::HEART));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      std::cerr << "hand failed to determine tie" << std::endl;
      status = false;
   }

   // test an ace low straight
   Hand hand5(Card(Rank::EIGHT,  Suit::SPADE),
              Card(Rank::SEVEN,  Suit::SPADE),
              Card(Rank::SIX,    Suit::HEART),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FOUR,   Suit::SPADE));
   Hand hand6(Card(Rank::ACE,    Suit::HEART),
              Card(Rank::FIVE,   Suit::DIAMOND),
              Card(Rank::FOUR,   Suit::CLUB),
              Card(Rank::THREE,  Suit::CLUB),
              Card(Rank::TWO,    Suit::HEART));
   PokerGame game3(hand5, hand6);
   std::cout << game3;
   if (game3.hasWinner())
   {
      if (game3.getWinner() != hand5)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::threeOfKindTest()
{
   bool status = true;
   std::cout << "three of kind test" << std::endl;

   Hand hand1(Card(Rank::QUEEN,  Suit::SPADE),
              Card(Rank::QUEEN,  Suit::CLUB),
              Card(Rank::QUEEN,  Suit::DIAMOND),
              Card(Rank::FIVE,   Suit::SPADE),
              Card(Rank::THREE,  Suit::CLUB));
   Hand hand2(Card(Rank::FIVE,   Suit::CLUB),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FIVE,   Suit::DIAMOND),
              Card(Rank::QUEEN,  Suit::CLUB),
              Card(Rank::TEN,    Suit::DIAMOND));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::EIGHT,  Suit::CLUB),
              Card(Rank::EIGHT,  Suit::HEART),
              Card(Rank::EIGHT,  Suit::DIAMOND),
              Card(Rank::ACE,    Suit::CLUB),
              Card(Rank::TWO,    Suit::DIAMOND));
   Hand hand4(Card(Rank::EIGHT,  Suit::SPADE),
              Card(Rank::EIGHT,  Suit::HEART),
              Card(Rank::EIGHT,  Suit::DIAMOND),
              Card(Rank::FIVE,   Suit::SPADE),
              Card(Rank::THREE,  Suit::CLUB));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::twoPairTest()
{
   bool status = true;
   std::cout << "two pair test" << std::endl;

   Hand hand1(Card(Rank::KING,   Suit::HEART),
              Card(Rank::KING,   Suit::DIAMOND),
              Card(Rank::TWO,    Suit::CLUB),
              Card(Rank::TWO,    Suit::DIAMOND),
              Card(Rank::JACK,   Suit::HEART));
   Hand hand2(Card(Rank::JACK,   Suit::DIAMOND),
              Card(Rank::JACK,   Suit::SPADE),
              Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::NINE,   Suit::SPADE));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::NINE,   Suit::CLUB),
              Card(Rank::NINE,   Suit::DIAMOND),
              Card(Rank::SEVEN,  Suit::DIAMOND),
              Card(Rank::SEVEN,  Suit::SPADE),
              Card(Rank::SIX,    Suit::HEART));
   Hand hand4(Card(Rank::NINE,   Suit::HEART),
              Card(Rank::NINE,   Suit::SPADE),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::FIVE,   Suit::DIAMOND),
              Card(Rank::KING,   Suit::CLUB));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand5(Card(Rank::FOUR,   Suit::SPADE),
              Card(Rank::FOUR,   Suit::CLUB),
              Card(Rank::THREE,  Suit::SPADE),
              Card(Rank::THREE,  Suit::HEART),
              Card(Rank::KING,   Suit::DIAMOND));
   Hand hand6(Card(Rank::FOUR,   Suit::HEART),
              Card(Rank::FOUR,   Suit::DIAMOND),
              Card(Rank::THREE,  Suit::DIAMOND),
              Card(Rank::THREE,  Suit::CLUB),
              Card(Rank::TEN,    Suit::SPADE));
   PokerGame game3(hand5, hand6);
   std::cout << game3;
   if (game3.hasWinner())
   {
      if (game3.getWinner() != hand5)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::onePairTest()
{
   bool status = true;
   std::cout << "one pair test" << std::endl;

   Hand hand1(Card(Rank::TEN,    Suit::CLUB),
              Card(Rank::TEN,    Suit::SPADE),
              Card(Rank::SIX,    Suit::SPADE),
              Card(Rank::FOUR,   Suit::HEART),
              Card(Rank::TWO,    Suit::HEART));
   Hand hand2(Card(Rank::NINE,   Suit::HEART),
              Card(Rank::NINE,   Suit::CLUB),
              Card(Rank::ACE,    Suit::HEART),
              Card(Rank::QUEEN,  Suit::DIAMOND),
              Card(Rank::TEN,    Suit::DIAMOND));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::TWO,    Suit::DIAMOND),
              Card(Rank::TWO,    Suit::HEART),
              Card(Rank::EIGHT,  Suit::SPADE),
              Card(Rank::FIVE,   Suit::CLUB),
              Card(Rank::FOUR,   Suit::CLUB));
   Hand hand4(Card(Rank::TWO,    Suit::CLUB),
              Card(Rank::TWO,    Suit::SPADE),
              Card(Rank::EIGHT,  Suit::CLUB),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::THREE,  Suit::HEART));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::highCardTest()
{
   bool status = true;
   std::cout << "high card test" << std::endl;

   Hand hand1(Card(Rank::ACE,    Suit::DIAMOND),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::NINE,   Suit::SPADE),
              Card(Rank::FIVE,   Suit::CLUB),
              Card(Rank::FOUR,   Suit::CLUB));
   Hand hand2(Card(Rank::KING,   Suit::CLUB),
              Card(Rank::QUEEN,  Suit::DIAMOND),
              Card(Rank::JACK,   Suit::CLUB),
              Card(Rank::EIGHT,  Suit::HEART),
              Card(Rank::SEVEN,  Suit::HEART));
   PokerGame game1(hand1, hand2);
   std::cout << game1;
   if (game1.hasWinner())
   {
      if (game1.getWinner() != hand1)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   Hand hand3(Card(Rank::ACE,    Suit::CLUB),
              Card(Rank::QUEEN,  Suit::CLUB),
              Card(Rank::SEVEN,  Suit::DIAMOND),
              Card(Rank::FIVE,   Suit::HEART),
              Card(Rank::TWO,    Suit::CLUB));
   Hand hand4(Card(Rank::ACE,    Suit::DIAMOND),
              Card(Rank::TEN,    Suit::DIAMOND),
              Card(Rank::NINE,   Suit::SPADE),
              Card(Rank::FIVE,   Suit::CLUB),
              Card(Rank::FOUR,   Suit::CLUB));
   PokerGame game2(hand3, hand4);
   std::cout << game2;
   if (game2.hasWinner())
   {
      if (game2.getWinner() != hand3)
      {
         std::cerr << "incorrect hand won" << std::endl;
         status = false;
      }
   }
   else
   {
      std::cerr << "hand failed to determine winner" << std::endl;
      status = false;
   }

   return status;
}

bool PokerTest::test()
{
   bool ret = true;

   sortTest();
   std::cout << std::endl << std::endl;

   if (!straightFlushTest())
   {
      std::cout << "straight flush test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!fourOfKindTest())
   {
      std::cout << "four of kind test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!fullHouseTest())
   {
      std::cout << "full house test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!flushTest())
   {
      std::cout << "flush test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!straightTest())
   {
      std::cout << "straight test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!threeOfKindTest())
   {
      std::cout << "three of a kind test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!twoPairTest())
   {
      std::cout << "two pair test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!onePairTest())
   {
      std::cout << "one pair test failed" << std::endl;
      ret = false;
   }
   std::cout << std::endl << std::endl;

   if (!highCardTest())
   {
      std::cout << "high card test failed" << std::endl;
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
   else
   {
      std::cout << "Poker test passes" << std::endl;
   }

   return 0;
}
