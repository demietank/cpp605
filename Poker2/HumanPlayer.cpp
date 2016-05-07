/*
 * HumanPlayer.cpp
 *
 *  Created on: May 6, 2016
 *      Author: cmmay
 */

#include <cassert>
#include <iostream>
#include <sstream>

#include "HumanPlayer.h"

namespace pokergame
{
using namespace std;

HumanPlayer::HumanPlayer(const unsigned int id) :
      Player(id)
{
}

HumanPlayer::~HumanPlayer()
{
}

CardCont HumanPlayer::discardCards()
{
   cout << *this << "| ";
   string msg {"select cards to discard, separated by commas "};

   CardCont discard;
   string discardStr;
   getUserInput(msg, discardStr);

   // Parse input into cards. If the player has that card, remove.
   stringstream ss(discardStr);
   string token;

   while(std::getline(ss, token, ','))
   {
      Card discardCard {Rank::ACE, Suit::SPADE};
      bool valid = getCardFromStr(token, discardCard);
      if (valid)
      {
         // check if player has that card
         for (auto card : mHand)
         {
            if (card == discardCard)
            {
               discard.emplace_back(card);
            }
         }

         // remove discarded cards from player
         for (auto cardInDiscard : discard)
         {
            for (auto it = mHand.begin(); it != mHand.end(); ++it)
            {
               if (*it == cardInDiscard)
               {
                  mHand.erase(it);
                  break;
               }
            }
         }
      }
   }

   cout << "discarded: ";
   for (auto card : discard)
   {
      cout << card;
   }
   cout << endl;

   return discard;
}

PlayerMove HumanPlayer::makeMove(const Chip potMinimum, Chip& raise)
{
   cout << *this << "| ";
   string msg {"fold (-1), stand (0), or call/raise (x) "};

   PlayerMove move;
   int playerEntry = 0;
   bool validEntry = false;
   while (!validEntry)
   {
      getUserInput(msg, playerEntry);
      Chip playerBet = static_cast<Chip>(playerEntry);
      Chip minimumBet = potMinimum - mChipsInPot;
      assert(mChipsInPot <= potMinimum);
      if (playerEntry == -1)
      {
         // fold
         validEntry = true;
         move = PlayerMove::FOLD;
      }
      else if (playerBet < minimumBet)
      {
         cerr << "minimum bet " << minimumBet <<", please try again" << endl;
      }
      else if (playerEntry == 0)
      {
         // stand - call is not required if minimum bet is zero
         validEntry = true;
         move = PlayerMove::STAND;
      }
      else if (playerEntry > 0)
      {
         // call/raise
         if (playerBet > mChips)
         {
            cerr << "insufficient number of chips, please try again" << endl;
         }
         else
         {
            validEntry = true;
            if (playerBet == minimumBet)
            {
               move = PlayerMove::CALL;
            }
            else
            {
               move = PlayerMove::RAISE;
               raise = playerBet - minimumBet;
            }
         }
      }
      else
      {
         cerr << "invalid entry, please try again" << endl;
      }
   }
   return move;
}

} /* namespace pokergame */
