/*
 * TicTacToe.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: Chris
 */

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

#include "BoardTest.h"
#include "TicTacToe.h"

namespace TicTacToeGame
{

void TicTacToe::runGame()
{
   std::cout << "Playing TicTacToe..." << std::endl;
   for (;;)
   {
      std::cout << mBoard << std::endl;
      if (gameOver())
      {
         break;
      }

      // take user turn;
      if (!makeMoveUser())
      {
         assert(false);
         break;
      }

      std::cout << mBoard << std::endl;
      if (gameOver())
      {
         break;
      }

      // take AI turn
      if (!makeMoveAI())
      {
         assert(false);
         break;
      }
   }
}

bool TicTacToe::gameOver() const
{
   bool ret;
   CellState winner;

   if (mBoard.hasWinner(winner))
   {
      std::cout << "Game over: " << winner << " wins!" << std::endl;
      ret = true;
   }
   else if (mBoard.isFull())
   {
      std::cout << "Game over: stalemate!" << std::endl;
      ret = true;
   }
   else
   {
      ret = false;
   }

   return ret;
}

void TicTacToe::getInput(unsigned int& row,
                         unsigned int& column) const
{
   // interpret user input as (row, column) separated by whitespace
   // initialize to an invalid input
   row = 0;
   column = 0;
   std::string strIn;

   std::cout << "Player X enter move [row] [column]:" << std::endl;

   // Note: this converts input to unsigned ints but performs no further data verification;
   // data verification is handled by Board.
   std::getline(std::cin, strIn);
   std::stringstream(strIn) >> row >> column;
}

bool TicTacToe::makeMoveUser()
{
   unsigned int row;
   unsigned int column;

   getInput(row, column);

   if (!mBoard.modifyCell(row, column, CellState::X))
   {
      std::cout << "invalid move: [" << row << "][" << column << "]" << std::endl;

      // ensure that the board is not full, then repeat
      if (!mBoard.isFull())
      {
         return makeMoveUser();
      }
      else
      {
         return false;
      }
   }
   else
   {
      return true;
   }
}

bool TicTacToe::makeMoveAI()
{
   for (unsigned int row = 1; row <= BOARD_SIZE; row++)
   {
      for (unsigned int column = 1; column <= BOARD_SIZE; column++)
      {
         if (mBoard.modifyCell(row, column, CellState::O))
         {
            return true;
         }
      }
   }

   return false;
}

} // end TicTacToeGame::

/**
 * @brief Entry point to a console based TicTacToe game.
 */
int main()
{
   using namespace TicTacToeGame;

   if (!BoardTest::testBoard())
   {
      std::cout << "Board failed negative testing." << std::endl;
   }

   TicTacToe game;
   game.runGame();

   return 0;
}
