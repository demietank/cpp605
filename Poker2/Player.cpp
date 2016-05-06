/*
 * Player.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Player.h"

namespace pokergame
{
using namespace std;

Player::Player(const unsigned int id) :
      mId(id),
      mChips(0),
      mIsActive(false),
      mInHand(false)
{
}

Player::~Player()
{
}

void Player::addCard(const Card card)
{
   mHand.emplace_back(card);
}


void Player::addChips(const Chip numChips)
{
   mChips += numChips;
}

void Player::addChipsToPot(const Chip numChips)
{
   if (numChips > mChips)
   {
      throw runtime_error("insufficient number of chips");
   }
   mChips -=numChips;
   mChipsInPot += numChips;
}

void Player::clearChipsInPot()
{
   mChipsInPot = 0;
}

void Player::setIsActive(const bool isActive)
{
   mIsActive = isActive;
}

void Player::setInHand(const bool inHand)
{
   mInHand = inHand;
}

PlayerMove Player::makeMove(const Chip potMinimum, Chip& raise)
{
   string msg {"Player: "};
   msg.append(to_string(mId)).append("; in pot: ").append(to_string(mChipsInPot)).
         append("; fold (-1), stand (0), or call/raise (x) ");

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

std::ostream& operator<<(std::ostream& out,
                         const Player& player)
{
   out << "Player: " << to_string(player.mId) << "; ";
   out << "chips: " << to_string(player.mChips) << "; ";
   if (player.isActive())
   {
      out << "in pot: " << to_string(player.mChipsInPot) << "; ";
   }
   else
   {
      out << "inactive; ";
   }
   out << (player.mInHand ? "in hand" : "out of hand") << "; ";
   out << "cards: ";
   for (auto& card : player.mHand)
   {
      out << card;
   }

   return out;
}

void getUserInput(const std::string& message, int& userInput)
{
   // get an input (unsigned int)
   while (1)
   {
      cout << message;
      string input;
      getline(cin, input);
      stringstream inputStream(input);
      if (inputStream >> userInput)
      {
         break;
      }
      else
      {
         cerr << "invalid number, please try again" << endl;
      }
   }
}

void getUserInput(const std::string& message, unsigned int& userInput)
{
   // get an input (unsigned int)
   while (1)
   {
      cout << message;
      string input;
      getline(cin, input);
      stringstream inputStream(input);
      if (inputStream >> userInput)
      {
         break;
      }
      else
      {
         cerr << "invalid number, please try again" << endl;
      }
   }
}

void getUserInput(const std::string& message, bool& yes)
{
   // get an input (string)
   cout << message << "(y/n) ";
   string input;
   getline(cin, input);
   stringstream inputStream(input);
   string inputStr;
   inputStream >> inputStr;

   // did she say yes?
   if ((inputStr.compare("y") == 0) || (inputStr.compare("yes") == 0))
   {
      yes = true;
   }
   else
   {
      yes = false;
   }
}

} /* namespace pokergame */
