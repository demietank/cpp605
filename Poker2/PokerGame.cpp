/*
 * PokerGame.cpp
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

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
   for (unsigned int i = 0; i < humanPlayers; ++i)
   {
      mPlayers.emplace_back(make_unique<Player>());
   }
   for (unsigned int i = 0; i < aiPlayers; ++i)
   {
      mPlayers.emplace_back(make_unique<Player>());
   }

   // give them some money
   for (auto& player : mPlayers)
   {
      player->addChips(buyIn);
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
}

void PokerGame::runTurn()
{
   cout << endl << "dealing new hand" << endl;
   mDeck.shuffle();

   // flop
   auto flopBurn = mDeck.getCard();
   auto flop1 = mDeck.getCard();
   auto flop2 = mDeck.getCard();
   auto flop3 = mDeck.getCard();
   cout << gameState(CardVec{flop1, flop2, flop3}, CardVec{flopBurn}, 10) << endl;

   // turn

   //river
}

std::string PokerGame::gameState(const CardVec& cardsInPlay,
                                 const CardVec& cardsBurned,
                                 unsigned int pot) const
{
   ostringstream stream;
   stream << "board:";
   for (const auto& card : cardsInPlay)
   {
      stream << card;
   }

   stream << endl << "burned:";
   for (const auto& card : cardsBurned)
   {
      stream << card;
   }

   stream << "; pot: " << to_string(pot);
   return stream.str();
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
         cout << "Invalid number, please try again" << endl;
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
