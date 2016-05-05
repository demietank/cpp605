/*
 * Player.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include <stdexcept>
#include <string>

#include "Player.h"

namespace pokergame
{

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
      throw std::runtime_error("insufficient number of chips");
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

std::ostream& operator<<(std::ostream& out,
                         const Player& player)
{
   out << "Player: " << std::to_string(player.mId) << "; ";
   out << "chips: " << std::to_string(player.mChips) << "; ";
   if (player.isActive())
   {
      out << "in pot: " << std::to_string(player.mChipsInPot) << "; ";
   }
   else
   {
      out << "inactive; ";
   }
   out << (player.mInHand ? "in hand" : "out") << "; ";
   out << "cards: ";
   for (auto& card : player.mHand)
   {
      out << card;
   }

   return out;
}

} /* namespace pokergame */
