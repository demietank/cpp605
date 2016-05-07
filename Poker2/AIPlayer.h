/*
 * AIPlayer.h
 *
 *  Created on: May 6, 2016
 *      Author: cmmay
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"

namespace pokergame
{
// An AI poker player who tries to skim on by.
class AIPlayer: public Player
{
public:
   // Constructs an AI player with no chips and no cards.
   AIPlayer(const unsigned int id);
   virtual ~AIPlayer();

   // Select cards to discard
   // The AI player never discards.
   CardCont discardCards();

   // Instruct the player to make a move based on a pot minimum.
   // The AI player always attempts to call.
   PlayerMove makeMove(const Chip potMinimum, Chip& raise);
};

} /* namespace pokergame */

#endif /* AIPLAYER_H_ */
