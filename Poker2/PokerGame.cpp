/*
 * PokerGame.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#include <algorithm>
#include <cassert>
#include <sstream>

#include "AIPlayer.h"
#include "HumanPlayer.h"
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
      mPlayers.emplace_back(make_unique<HumanPlayer>(id));
   }
   for (unsigned int i = 0; i < aiPlayers; ++i, ++id)
   {
      mPlayers.emplace_back(make_unique<AIPlayer>(id));
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
   unsigned int playersLeft = mPlayers.size();
   while (playersLeft >= NUM_PLAYERS_MIN)
   {
      runTurn();

      // remove players who cannot afford a big blind
      // check if there are at least two players remaining
      playersLeft = 0;
      for (auto& player : mPlayers)
      {
         if (player->getChips() < (mBlind * 2))
         {
            player->setIsActive(false);
            cout << "Player: " << player->getId() <<  " eliminated!" << endl;
         }

         if (player->isActive())
         {
            playersLeft++;
         }
      }
   }

   // Output winner
   for (auto& player : mPlayers)
   {
      if (player->isActive())
      {
         cout << "Player: " << player->getId() <<  " wins!" << endl;
      }
   }
}

void PokerGame::playerDraw()
{
   for (auto& player : mPlayers)
   {
      if (player->isActive() && player->inHand())
      {
         auto discarded = player->discardCards();
         if (!discarded.empty())
         {
            for (auto card : discarded)
            {
               mDeck.addCard(card);
               player->addCard(mDeck.getCard());
            }
         }
      }
   }
}

StartStop PokerGame::placeBets(const Chip potMinimum,
                               const StartStop startStop,
                               Chip& pot,
                               Chip& potMinimumNew)
{
   StartStop nextSS = startStop;
   potMinimumNew = potMinimum;

   do
   {
      auto& player = **(nextSS.first);
      if (player.isActive() && player.inHand())
      {
         if ((player.getChips() + player.getChipsInPot()) < potMinimum)
         {
            // side pots not supported, kick out of hand
            cerr << "player " << player.getId() << "can't afford to stay in hand, sorry bro" << endl;
            player.setInHand(false);
            player.setIsActive(false);
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
               auto playerBet = potMinimum - player.getChipsInPot() + raise;
               player.addChipsToPot(playerBet);
               pot += playerBet;
               potMinimumNew += raise;

               // we have a raise, terminate signaled by new pot minimum
               nextSS.second = nextSS.first;
            }
         }
      }

      // perform circular iteration of the next bettor, if necessary
      ++nextSS.first;
      if (nextSS.first == mPlayers.end())
      {
         nextSS.first = mPlayers.begin();
      }
   } while((nextSS.first != startStop.second) && (potMinimumNew == potMinimum));

   return nextSS;
}

void PokerGame::bettingRound(Chip& pot,
                             Chip& potMinimum)
{
   //ask players to fold/call/raise
   // initial round permits all players to bet
   StartStop startStop {mPlayers.begin(), mPlayers.begin()};
   while(true)
   {
      cout << "player pot minimum: " << potMinimum << endl;
      startStop = placeBets(potMinimum, startStop, pot, potMinimum);

      // did someone raise?
      if (startStop.first == startStop.second)
      {
         break;
      }
   };
}

PlayerCont::iterator PokerGame::determineWinner()
{
   PlayerCont::iterator winner = mPlayers.end();

   // get the first player in the hand
   for (auto it = mPlayers.begin(); it != mPlayers.end(); ++it)
   {
      if ((*it)->isActive() && (*it)->inHand())
      {
         winner = it;
         break;
      }
   }
   auto winningHand = (*winner)->makeHand();

   // check if any other player can beat his hand
   for (auto it = winner + 1; it != mPlayers.end(); ++it)
   {
      if ((*it)->isActive() && (*it)->inHand())
      {
         auto playerHand = (*it)->makeHand();
         auto outcome = winningHand.getWinner(playerHand);
         if (outcome == HandComparrison::LOSES)
         {
            winner = it;
            winningHand = playerHand;
         }
         else if (outcome == HandComparrison::TIES)
         {
            cerr << "tie between players " << (*winner)->getId() << " & " << (*it)->getId()
                  << "! preference given to player " << (*winner)->getId() << endl;
         }
      }
   }

   assert(winner != mPlayers.end());
   return winner;
}

void PokerGame::runTurn()
{
   Chip pot = 0;
   auto potMinimum = mBlind * 2;
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
         for (unsigned int i = 0; i < CARDS_PER_HAND; ++i)
         {
            player->addCard(mDeck.getCard());
         }
      }
   }

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

   cout << endl << gameState(pot) << endl;
   /**********************************************************************************************/

   // Betting Round #1
   cout << "Betting Round #1" << endl;
   rotate(mPlayers.begin(), mPlayers.begin() + 2, mPlayers.end()); // start after big blind
   bettingRound(pot, potMinimum);
   rotate(mPlayers.rbegin(), mPlayers.rbegin() + 2, mPlayers.rend());
   cout << endl << gameState(pot) << endl;

   // Draw #1
   cout << "Draw #1" << endl;
   playerDraw();
   cout << endl << gameState(pot) << endl;

   // Betting Round #2
   cout << "Betting Round #2" << endl;
   bettingRound(pot, potMinimum);
   cout << endl << gameState(pot) << endl;

   // Draw #2
   cout << "Draw #2" << endl;
   playerDraw();
   cout << endl << gameState(pot) << endl;

   // player with best hand wins
   auto winner = determineWinner();
   cout << "Player: " << (*winner)->getId() <<  " wins hand!" << endl;
   (*winner)->addChips(pot);
   pot = 0;

   // clean up
   for (auto& player : mPlayers)
   {
      auto discard = player->clearHand();
      for (auto card : discard)
      {
         mDeck.addCard(card);
      }
      player->setInHand(false);
      player->clearChipsInPot();
   }

   cout << endl << gameState(pot) << endl;
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
