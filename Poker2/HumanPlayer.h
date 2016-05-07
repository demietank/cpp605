/*
 * HumanPlayer.h
 *
 *  Created on: May 6, 2016
 *      Author: cmmay
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

namespace pokergame
{
// A human poker player who inputs moves through the console.
class HumanPlayer: public Player
{
public:
   // Constructs a human player with no chips and no cards.
   HumanPlayer(const unsigned int id);
   virtual ~HumanPlayer();

   // Select cards to discard
   CardCont discardCards();

   // Instruct the player to make a move based on a pot minimum.
   PlayerMove makeMove(const Chip potMinimum, Chip& raise);
};

} /* namespace pokergame */

#endif /* HUMANPLAYER_H_ */
