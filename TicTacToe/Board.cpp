/*
 * Board.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: Chris
 */

#include "Board.h"

namespace TicTacToeGame
{

Board::Board()
{
   reset();
}

bool Board::hasWinner(CellState& winner) const
{
   bool ret = false;

   // check for a winner in a row
   for (const auto& row : mCells)
   {
      auto hasRowWinner = true;
      auto rowWinner = row.front();
      if (rowWinner == CellState::EMPTY)
      {
         // row does not contain a winner, move on to next one
         continue;
      }

      // check if the entire row matches the first cell
      for (const auto& cell : row)
      {
         if (rowWinner != cell)
         {
            hasRowWinner = false;
            break;
         }
      }

      if (hasRowWinner)
      {
         // row contains a winner, don't check any more
         ret = true;
         winner = rowWinner;
         break;
      }
   }

   // check for a winner in a column
   if (!ret)
   {
      for (unsigned int iCol = 0; iCol < BOARD_SIZE; iCol++)
      {
         auto hasColWinner = true;
         auto colWinner = mCells.at(0).at(iCol);
         if (colWinner == CellState::EMPTY)
         {
            // column does not contain a winner, move on to next one
            continue;
         }

         for (unsigned int iRow = 0; iRow < BOARD_SIZE; iRow++)
         {
            if (colWinner != mCells.at(iRow).at(iCol))
            {
               hasColWinner = false;
               break;
            }
         }

         if (hasColWinner)
         {
            // column contains a winner, don't check any more
            ret = true;
            winner = colWinner;
            break;
         }
      }
   }

   // check for a winner in a diagonal
   if (!ret)
   {
      // Note:: This segment purposefully checks absolute locations on the board to significantly
      // reduce complexity.
      auto diagWinner = mCells.at(1).at(1);
      if (diagWinner != CellState::EMPTY)
      {
         if ((diagWinner == mCells.at(0).at(0)) && (diagWinner == mCells.at(2).at(2)))
         {
            // diagonal contains a winner
            ret = true;
            winner = diagWinner;
         }
         else if ((diagWinner == mCells.at(0).at(2)) && (diagWinner == mCells.at(2).at(0)))
         {
            // diagonal contains a winner
            ret = true;
            winner = diagWinner;
         }
      }
   }

   return ret;
}

bool Board::isFull() const
{
   bool hasEmpty = false;

   for (const auto& row : mCells)
   {
      for (const auto& cell : row)
      {
         if (cell == CellState::EMPTY)
         {
            hasEmpty = true;
            break;
         }
      }

      if (hasEmpty)
      {
         break;
      }
   }

   return !hasEmpty;
}

bool Board::modifyCell(const unsigned int row,
                       const unsigned int column,
                       const CellState state)
{
   bool ret;

   // Transform to zero-indexing.
   auto zRow = row - 1;
   auto zColumn = column - 1;

   if ((row == 0) || (column == 0) || (zRow >= BOARD_SIZE) || (zColumn >= BOARD_SIZE))
   {
      ret = false;
   }
   else if (mCells.at(zRow).at(zColumn) != CellState::EMPTY)
   {
      ret = false;
   }
   else
   {
      mCells.at(zRow).at(zColumn) = state;
      ret = true;
   }

   return ret;
}

void Board::reset()
{
   mCells =
   {{
      {{  CellState::EMPTY, CellState::EMPTY, CellState::EMPTY}},
      {{  CellState::EMPTY, CellState::EMPTY, CellState::EMPTY}},
      {{  CellState::EMPTY, CellState::EMPTY, CellState::EMPTY}}
   }};
}

std::ostream& operator<<(std::ostream& out,
                         const CellState state)
{
   const char * s = 0;
   switch (state)
   {
   case CellState::EMPTY:
      s = " ";
      break;
   case CellState::X:
      s = "X";
      break;
   case CellState::O:
      s = "O";
      break;
   default:
      s = " ";
      break;
   }

   return out << s;
}

std::ostream& operator<<(std::ostream& out,
                         const Board& board)
{
   constexpr const char * CELL_BOARDER_HORIZONTAL = " ---";
   constexpr const char * CELL_BOARDER_VERTICAL = "|";

   // Print the board line by line
   for (const auto& row : board.mCells)
   {
      // top boarder of row
      for (unsigned int i = 0; i < BOARD_SIZE; i++)
      {
         out << CELL_BOARDER_HORIZONTAL;
      }
      out << std::endl;

      // cell left boarder and contents
      for (const auto& cell : row)
      {
         out << CELL_BOARDER_VERTICAL << " " << cell << " ";
      }

      // right boarder of row
      out << CELL_BOARDER_VERTICAL << std::endl;
   }

   // bottom boarder of last row
   for (unsigned int i = 0; i < BOARD_SIZE; i++)
   {
      out << CELL_BOARDER_HORIZONTAL;
   }
   out << std::endl;

   return out;
}

} // end TicTacToeGame::
