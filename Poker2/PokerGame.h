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
using StartStop = std::pair<PlayerCont::iterator, PlayerCont::iterator>;

// A rudimentary poker game consisting of human and AI players.
// Blinds are fixed and do not increase. Players who cannot afford a blind are booted.
// No re-buys.
// All betting numbers are in units of chips.
// Human players go in order, then AI players.
// There are no burn cards
// There are no ties.
class PokerGame
{
public:
   // Constructs a poker game.
   PokerGame(const unsigned int humanPlayers,
             const unsigned int aiPlayers,
             const Chip blind,
             const Chip buyIn);
   virtual ~PokerGame();

   // Run the game until a winner is determined.
   void runGame();

private:
   // Performs a round of betting, where every active player is given the opportunity to
   // increase their pot contribution to match the current minimum. Players can choose to
   // raise the pot minimum; this results in the function terminating early, indicating the new
   // pot minimum and the player who raised.
   // Returns an iterator to the next player to take action. If that equals begin, every player took action.
   // Returns the number of chips added to the pot
   // Returns the new pot pot minimum
   StartStop placeBets(const Chip potMinimum,
                       const StartStop startStop,
                       Chip& pot,
                       Chip& potMinimumNew);

   // Ask players to fold/call/raise (starting with player after big blind)
   // both inputs are in/out
   void bettingRound(Chip& pot,
                     Chip& potMinimum);

   // Returns a pointer to the active player in the hand (round) with the best hand (cards).
   PlayerCont::iterator determineWinner();

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
