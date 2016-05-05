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
   Chip placeBets(Chip minimumBet);
   void runTurn();
   std::string gameState(unsigned int pot) const;

   unsigned int mBlind;
   Deck mDeck;

   // players in the game, both active and inactive
   // at the start of a turn, the first player of the container has the button
   PlayerCont mPlayers;
};

// Output a prompt to the user and get a valid response.
void getUserInput(const std::string& message, int& userInput);
void getUserInput(const std::string& message, unsigned int& userInput);
void getUserInput(const std::string& message, bool& yes);

} /* namespace pokergame */

#endif /* POKERGAME_H_ */
