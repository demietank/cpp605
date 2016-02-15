/*
 * BoardTest.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: Chris
 */

#include "Board.h"
#include "BoardTest.h"

namespace TicTacToeGame
{

bool BoardTest::testBoard()
{
   bool ret;

   ret = testModifyCell();

   if (ret)
   {
      ret = testRowWinner();
   }

   if (ret)
   {
      ret = testColWinner();
   }

   if (ret)
   {
      ret = testDiagWinner();
   }

   if (ret)
   {
      ret = testIsFull();
   }

   return ret;
}

bool BoardTest::testModifyCell()
{
   bool ret = true;
   Board board;

   // out of index
   if (board.modifyCell(0, 1, CellState::X))
   {
      ret = false;
   }
   if (board.modifyCell(1, 0, CellState::X))
   {
      ret = false;
   }
   if (board.modifyCell(BOARD_SIZE + 1, 1, CellState::X))
   {
      ret = false;
   }
   if (board.modifyCell(1, BOARD_SIZE + 1, CellState::X))
   {
      ret = false;
   }

   // set a cell, then try and set it again
   if (!board.modifyCell(1, 1, CellState::X))
   {
      ret = false;
   }
   else
   {
      if (board.modifyCell(1, 1, CellState::O))
      {
         ret = false;
      }
   }

   return ret;
}

bool BoardTest::testRowWinner()
{
   constexpr const auto EXP_WINNER = CellState::X;
   bool ret = true;
   Board board;

   for (unsigned int i = 1; i <= BOARD_SIZE; i++)
   {
      CellState winner;
      board.reset();
      if (board.hasWinner(winner))
      {
         ret = false;
      }
      else
      {
         if (!board.modifyCell(i, 1, EXP_WINNER) || board.hasWinner(winner))
         {
            ret = false;
         }
         if (!board.modifyCell(i, 2, EXP_WINNER) || board.hasWinner(winner))
         {
            ret = false;
         }
         if (!board.modifyCell(i, 3, EXP_WINNER) || !board.hasWinner(winner))
         {
            ret = false;
         }
         else
         {
            if (winner != EXP_WINNER)
            {
               ret = false;
            }
         }
      }
   }

   return ret;
}

bool BoardTest::testColWinner()
{
   constexpr const auto EXP_WINNER = CellState::X;
   bool ret = true;
   Board board;

   for (unsigned int i = 1; i <= BOARD_SIZE; i++)
   {
      CellState winner;
      board.reset();
      if (board.hasWinner(winner))
      {
         ret = false;
      }
      else
      {
         if (!board.modifyCell(1, i, EXP_WINNER) || board.hasWinner(winner))
         {
            ret = false;
         }
         if (!board.modifyCell(2, i, EXP_WINNER) || board.hasWinner(winner))
         {
            ret = false;
         }
         if (!board.modifyCell(3, i, EXP_WINNER) || !board.hasWinner(winner))
         {
            ret = false;
         }
         else
         {
            if (winner != EXP_WINNER)
            {
               ret = false;
            }
         }
      }
   }

   return ret;
}

bool BoardTest::testDiagWinner()
{
   constexpr const auto EXP_WINNER = CellState::X;
   bool ret = true;
   Board board;
   CellState winner;

   if (!board.modifyCell(1, 1, EXP_WINNER) || board.hasWinner(winner))
   {
      ret = false;
   }
   if (!board.modifyCell(2, 2, EXP_WINNER) || board.hasWinner(winner))
   {
      ret = false;
   }
   if (!board.modifyCell(3, 3, EXP_WINNER) || !board.hasWinner(winner))
   {
      ret = false;
   }
   else
   {
      if (winner != EXP_WINNER)
      {
         ret = false;
      }
   }

   board.reset();
   winner = CellState::EMPTY;
   if (!board.modifyCell(1, 3, EXP_WINNER) || board.hasWinner(winner))
   {
      ret = false;
   }
   if (!board.modifyCell(2, 2, EXP_WINNER) || board.hasWinner(winner))
   {
      ret = false;
   }
   if (!board.modifyCell(3, 1, EXP_WINNER) || !board.hasWinner(winner))
   {
      ret = false;
   }
   else
   {
      if (winner != EXP_WINNER)
      {
         ret = false;
      }
   }

   return ret;
}

bool BoardTest::testIsFull()
{
   bool ret = true;
   Board board;

   if (board.isFull())
   {
      ret = false;
   }
   else
   {
      for (unsigned int i = 1; i <= BOARD_SIZE; i++)
      {
         for (unsigned int j = 1; j <= BOARD_SIZE; j++)
         {
            if (!board.modifyCell(i, j, CellState::X))
            {
               ret = false;
            }
         }
      }

      if (ret)
      {
         ret = board.isFull();
      }
   }

   return ret;
}

} // end TicTacToeGame::
