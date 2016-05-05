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
   // TODO Auto-generated destructor stub
}

void PokerGame::runGame()
{
   runTurn();

   // remove players who cannot afford a big blind
   // check if there are at least two players remaining
}

Chip PokerGame::placeBets(Chip minimumBet)
{
   Chip bets = 0;
   for (auto& player : mPlayers)
   {
      if (player->isActive())
      {
         int playerEntry = 0;
         string msg {"Player: "};
         msg.append(to_string(player->getId())).append("; fold (-1), call (0), or raise (x) ");
         bool validEntry = false;
         while (!validEntry)
         {
            getUserInput(msg, playerEntry);
            if (playerEntry == - 1)
            {
               // fold
               validEntry = true;
            }
            else if (playerEntry == 0)
            {
               // call
               validEntry = true;
            }
            else if (playerEntry > 0)
            {
               // raise
               if (playerEntry > static_cast<int>(player->getChips()))
               {
                  cerr << "insufficient number of chips, please try again" << endl;
               }
               else if (playerEntry < static_cast<int>(minimumBet))
               {
                  cerr << "minimum bet " << minimumBet <<", please try again" << endl;
               }
               else
               {
                  validEntry = true;
               }
            }
            else
            {
               cerr << "invalid entry, please try again" << endl;
            }
         }

         // input sanitized
         if (playerEntry == -1)
         {
            player->setInHand(false);
         }
         else if (playerEntry == 0)
         {
            bets += minimumBet;
         }
         bets += playerEntry;
      }
   }
   return bets;
}

void PokerGame::runTurn()
{
   Chip pot = 0;
   cout << endl << "dealing new hand" << endl;
   mDeck.shuffle();

   // deal each player 5 cards (starting with the player after the button)
   std::rotate(mPlayers.begin(), mPlayers.begin() + 1, mPlayers.end());
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

   // place blinds
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
   std::rotate(mPlayers.begin(), mPlayers.begin() + 2, mPlayers.end());
   pot += placeBets(mBlind * 2);
   cout << endl << gameState(pot) << endl;

   // betting round #1
   // ask players to fold/call/raise (starting with player after the button)
   // display then ask remaining players which cards they wish to discard; draw cards to replace discarded

   // betting round #2
   // ask players to fold/call/raise (starting with player after the button)
   // display then ask remaining players which cards they wish to discard; draw cards to replace discarded

   // showdown
   // player with best hand wins

   // return cards to deck
}

std::string PokerGame::gameState(unsigned int pot) const
{
   ostringstream stream;
   stream << "pot: " << to_string(pot) << endl;

   for (const auto& player : mPlayers)
   {
      stream << *player << endl;
   }

   return stream.str();
}

void getUserInput(const std::string& message, int& userInput)
{
   // get an input (unsigned int)
   while (1)
   {
      cout << message;
      string input;
      getline(cin, input);
      stringstream inputStream(input);
      if (inputStream >> userInput)
      {
         break;
      }
      else
      {
         cerr << "invalid number, please try again" << endl;
      }
   }
}

void getUserInput(const std::string& message, unsigned int& userInput)
{
   // get an input (unsigned int)
   while (1)
   {
      cout << message;
      string input;
      getline(cin, input);
      stringstream inputStream(input);
      if (inputStream >> userInput)
      {
         break;
      }
      else
      {
         cerr << "invalid number, please try again" << endl;
      }
   }
}

void getUserInput(const std::string& message, bool& yes)
{
   // get an input (string)
   cout << message << "(y/n) ";
   string input;
   getline(cin, input);
   stringstream inputStream(input);
   string inputStr;
   inputStream >> inputStr;

   // did she say yes?
   if ((inputStr.compare("y") == 0) || (inputStr.compare("yes") == 0))
   {
      yes = true;
   }
   else
   {
      yes = false;
   }
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
