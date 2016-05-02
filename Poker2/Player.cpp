/*
 * Player.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include <stdexcept>

#include "Player.h"

namespace pokergame
{

Player::Player() :
      mChips(0),
      mIsActive(false),
      mInHand(false)
{
}

Player::~Player()
{
}

void Player::addChips(const Chip numChips)
{
   mChips += numChips;
}

void Player::removeChips(const Chip numChips)
{
   if (numChips > mChips)
   {
      throw std::runtime_error("insufficient number of chips");
   }
   mChips -=numChips;
}

void Player::setIsActive(const bool isActive)
{
   mIsActive = isActive;
}

void Player::setInHand(const bool inHand)
{
   mInHand = inHand;
}

} /* namespace pokergame */
