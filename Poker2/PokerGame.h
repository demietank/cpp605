/*
 * PokerGame.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef POKERGAME_H_
#define POKERGAME_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

namespace pokergame
{

/// Used for convenience
using std::make_unique;
using Player_ptr = std::unique_ptr<Player>;
using PlayerCont = std::vector<Player_ptr>;

// A rudimentary poker game consisting of human and AI players.
// Blinds are fixed and do not increase. Players who cannot afford a blind are booted.
// No re-buys
// All betting numbers are in units of chips and must be greater than big blind.
// Human players go in order, then AI players.
// There are no burn cards
class PokerGame
{
public:
   PokerGame(const unsigned int humanPlayers,
             const unsigned int aiPlayers,
             const Chip blind,
             const Chip buyIn);
   virtual ~PokerGame();


   void runGame();

private:
   // Performs a round of betting, where every active player is given the opportunity to
   // increase their pot contribution to match the current minimum. Players can choose to
   // raise the pot minimum; this results in the function terminating early, indicating the new
   // pot minimum and the player who raised.
   // Returns an iterator to the next player to take action. If that equals begin, every player took action.
   // Returns the number of chips added to the pot
   // Returns the new pot pot minimum
   PlayerCont::iterator placeBets(const Chip potMinimum,
                                  const PlayerCont::iterator begin,
                                  const PlayerCont::iterator end,
                                  Chip& pot,
                                  Chip& potMinimumNew);

   // Deals active players cards and lets them play a round of 5 card draw.
   void runTurn();

   // Outputs a string representing the state of the game.
   std::string gameState(const unsigned int pot) const;

   Chip mBlind;   // Small blind (fixed).
   Deck mDeck;    // Dealer's deck of cards.

   // players in the game, both active and inactive
   // at the start of a turn, the first player of the container has the button
   PlayerCont mPlayers;
};

} /* namespace pokergame */

#endif /* POKERGAME_H_ */
