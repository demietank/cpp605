/*
 * PokerGame.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include <algorithm>
#include <cassert>
#include <sstream>

#include "PokerGame.h"

namespace pokergame
{

using namespace std;
constexpr unsigned int NUM_PLAYERS_MIN = 2;
constexpr unsigned int NUM_PLAYERS_MAX = 7;

PokerGame::PokerGame(const unsigned int humanPlayers,
                     const unsigned int aiPlayers,
                     const Chip blind,
                     const Chip buyIn) :
                           mBlind(blind)
{
   assert((humanPlayers + aiPlayers) >= NUM_PLAYERS_MIN);
   assert((humanPlayers + aiPlayers) <= NUM_PLAYERS_MAX);

   // add players
   unsigned int id = 1;
   for (unsigned int i = 0; i < humanPlayers; ++i, ++id)
   {
      mPlayers.emplace_back(make_unique<Player>(id));
   }
   for (unsigned int i = 0; i < aiPlayers; ++i, ++id)
   {
      mPlayers.emplace_back(make_unique<Player>(id));
   }

   // give them some money and set them as active
   for (auto& player : mPlayers)
   {
      player->addChips(buyIn);
      player->setIsActive(true);
   }

   mDeck.shuffle();
}

PokerGame::~PokerGame()
{
}

void PokerGame::runGame()
{
   runTurn();

   // remove players who cannot afford a big blind
   // check if there are at least two players remaining
}

PlayerCont::iterator PokerGame::placeBets(const Chip potMinimum,
                                          const PlayerCont::iterator begin,
                                          const PlayerCont::iterator end,
                                          Chip& pot,
                                          Chip& potMinimumNew)
{
   auto nextAction = begin;
   potMinimumNew = potMinimum;

   do
   {
      auto& player = **nextAction;
      if (player.isActive() && player.inHand())
      {
         if ((player.getChips() + player.getChipsInPot()) < potMinimum)
         {
            // side pots not supported, kick out of hand
            cerr << "player " << player.getId() << "can't afford to stay in hand, sorry bro" << endl;
            player.setInHand(false);
         }
         else
         {
            Chip raise;
            auto playerMove = player.makeMove(potMinimum, raise);
            if (playerMove == PlayerMove::FOLD)
            {
               player.setInHand(false);
            }
            else if (playerMove == PlayerMove::STAND)
            {
               // no action
            }
            else if (playerMove == PlayerMove::CALL)
            {
               auto playerBet = potMinimum - player.getChipsInPot();
               player.addChipsToPot(playerBet);
               pot += playerBet;
            }
            else // raise
            {
               auto playerBet = potMinimum + raise;
               player.addChipsToPot(playerBet);
               pot += playerBet;
               potMinimumNew += raise;

               // we have a raise, terminate signaled by new pot minimum
            }
         }
      }

      // perform circular iteration, if necessary
      if (end != mPlayers.end())
      {
         nextAction = (nextAction + 1 != mPlayers.end()) ? nextAction + 1 : mPlayers.begin();
      }
      else
      {
         ++nextAction;
      }
   } while((nextAction != end) && (potMinimumNew == potMinimum));

   return nextAction;
}

void PokerGame::runTurn()
{
   Chip pot = 0;
   cout << endl << "dealing new hand" << endl;
   mDeck.shuffle();

   // deal each player 5 cards (starting with the player after the button)
   rotate(mPlayers.begin(), mPlayers.begin() + 1, mPlayers.end());
   for (auto& player : mPlayers)
   {
      if (player->isActive())
      {
         player->setInHand(true);
         player->clearChipsInPot();
         for (int i = 0; i < 5; ++i)
         {
            player->addCard(mDeck.getCard());
         }
      }
   }
   cout << gameState(pot) << endl;

   /*********************************** Place Blinds *********************************************/
   // small and big automatic;
   bool smallBlind = true;
   for (auto& player : mPlayers)
   {
      if (player->isActive())
      {
         if (smallBlind)
         {
            player->addChipsToPot(mBlind);
            pot += mBlind;
            smallBlind = false;
         }
         else
         {
            player->addChipsToPot(mBlind * 2);
            pot += mBlind * 2;
            break;
         }
      }
   }

   //ask players to fold/call/raise (starting with player after big blind)
   rotate(mPlayers.begin(), mPlayers.begin() + 2, mPlayers.end());
   auto potMinimum = mBlind * 2;
   auto nextBettor = mPlayers.begin();
   auto finalBettor = mPlayers.end();
   while(true)
   {
      cout << "new player pot minimum: " << potMinimum << endl;
      nextBettor = placeBets(potMinimum, nextBettor, finalBettor, pot, potMinimum);

      // did someone raise?
      if (nextBettor != finalBettor)
      {
         finalBettor = (nextBettor != mPlayers.begin()) ? nextBettor - 1 : mPlayers.end();
      }
      else
      {
         break;
      }
   };

   cout << endl << gameState(pot) << endl;
   /**********************************************************************************************/

   /*********************************** Betting Round #1 *****************************************/
   // ask players to fold/call/raise (starting with player after the button)
   // display then ask remaining players which cards they wish to discard; draw cards to replace discarded

   //cout << endl << gameState(pot) << endl;
   /**********************************************************************************************/

   /*********************************** Betting Round #2 *****************************************/
   // ask players to fold/call/raise (starting with player after the button)
   // display then ask remaining players which cards they wish to discard; draw cards to replace discarded

   //cout << endl << gameState(pot) << endl;
   /**********************************************************************************************/

   // showdown
   // player with best hand wins

   // return cards to deck
}

std::string PokerGame::gameState(const unsigned int pot) const
{
   ostringstream stream;
   stream << "pot: " << to_string(pot) << endl;

   for (const auto& player : mPlayers)
   {
      stream << *player << endl;
   }

   return stream.str();
}

} /* namespace pokergame */

int main()
{
   using namespace pokergame;
   constexpr Chip BLIND = 10;
   constexpr Chip BUY_IN = 100;
   bool validGame = false;
   unsigned int numHumans;
   unsigned int numAI;

   cout << "Starting a new poker game..." << endl;
   // get user input for game configuration
   do
   {
      getUserInput("How many human players? ", numHumans);
      getUserInput("How many AI players? ", numAI);
      if ((numHumans + numAI < NUM_PLAYERS_MIN) || (numHumans + numAI > NUM_PLAYERS_MAX))
      {
         std::cout << "Invalid number of players (2-7)" << std::endl;
      }
      else
      {
         // Invalid inputs are set to zero. Let the user verify.
         std::cout << "Human players: " << numHumans << std::endl;
         std::cout << "AI players: " << numAI << std::endl;
         getUserInput("Is this correct? ", validGame);
      }
   } while(!validGame);

   PokerGame game {numHumans, numAI, BLIND, BUY_IN};
   game.runGame();

   return 0;
}
