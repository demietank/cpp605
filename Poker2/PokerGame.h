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

using std::make_unique;

/// Used for convenience
using Player_ptr = std::unique_ptr<Player>;
using CardVec = std::vector<Card>;

// A rudimentary poker game consisting of human and AI players.
// Blinds are fixed and do not increase.
// All betting numbers are in units of chips
// Human players go in order, then AI players.
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
   void runTurn();
   std::string gameState(const CardVec& cardsInPlay,
                         const CardVec& cardsBurned,
                         unsigned int pot) const;

   unsigned int mBlind;
   std::vector<Player_ptr> mPlayers;
   Deck mDeck;
};

// Output a prompt to the user and get a valid response.
void getUserInput(const std::string& message, unsigned int& userInput);
void getUserInput(const std::string& message, bool& yes);

} /* namespace pokergame */

#endif /* POKERGAME_H_ */
