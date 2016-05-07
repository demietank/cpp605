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

CardCont Player::clearHand()
{
   CardCont ret = mHand;
   mHand.clear();
   return ret;
}

void Player::setIsActive(const bool isActive)
{
   mIsActive = isActive;
}

void Player::setInHand(const bool inHand)
{
   mInHand = inHand;
}

Hand Player::makeHand() const
{
   assert(mHand.size() == CARDS_PER_HAND);
   return Hand {mHand.at(0), mHand.at(1), mHand.at(2), mHand.at(3), mHand.at(4)};
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

   // use Hand if possible for sorting
   if (player.mHand.size() == CARDS_PER_HAND)
   {
      out << player.makeHand();
   }
   else
   {
      for (auto& card : player.mHand)
      {
         out << card;
      }
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

void getUserInput(const std::string& message, std::string& inputStr)
{
   // get an input (string)
   cout << message;
   string input;
   getline(cin, input);
   stringstream inputStream(input);
   inputStream >> inputStr;
}

} /* namespace pokergame */
