/*
 * AIPlayer.cpp
 *
 *  Created on: May 6, 2016
 *      Author: cmmay
 */

#include "AIPlayer.h"

namespace pokergame
{

AIPlayer::AIPlayer(const unsigned int id) :
      Player(id)
{
}

AIPlayer::~AIPlayer()
{
}

CardCont AIPlayer::discardCards()
{
   CardCont discard;
   return discard;
}

PlayerMove AIPlayer::makeMove(const Chip potMinimum, Chip& raise)
{
   (void)raise; // unused
   PlayerMove move = PlayerMove::FOLD;

   Chip minimumBet = potMinimum - mChipsInPot;
   if (mChips >= minimumBet)
   {
      move = PlayerMove::CALL;
   }

   return move;
}

} /* namespace pokergame */
