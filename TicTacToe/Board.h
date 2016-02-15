/*
 * Board.h
 *
 *  Created on: Feb 13, 2016
 *      Author: Chris
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <ostream>

namespace TicTacToeGame
{

/**
 * @brief Dimension of the square board.
 */
constexpr const unsigned int BOARD_SIZE = 3;

/**
 * @brief The contents of a board cell.
 */
enum class CellState
{
   EMPTY, ///< Cell is empty.
   X,     ///< Cell contains an 'X'.
   O      ///< Cell contains an 'O'.
};

/**
 * @brief The playing board of a TicTacToe game.
 *
 * @details
 *    This class is responsible for tracking the current state of the game, modifying the state,
 *    and determining whether there is a winner.
 */
class Board
{
public:
   /**
    * @brief Constructs an empty board.
    */
   Board();

   /**
    * @brief Determines whether the board has a winning player.
    *
    * @details
    *    A winning player is defined as a player that has all cells in a row, column, or diagonal.
    *
    * @note: If there is more than one winning player on the board the result is undefined.
    *
    * @param[out] winner The winning player, if any.
    *
    * @return Whether the board has a winning player.
    * @retval true  The board has a winner.
    * @retval false The board doesn't have a winner.
    */
   bool hasWinner(CellState& winner) const;

   /**
    * @brief Determines whether the board is full.
    *
    * @return Whether the board is full.
    * @retval true  The board is full.
    * @retval false The board is not full.
    */
   bool isFull() const;

   /**
    * @brief Modify the contents of a board cell; One-indexed.
    *
    * @details Only empty cells are permitted to be modified.
    *
    * @param[in] row    Row of the cell to modify.
    * @param[in] column Column of the cell to modify.
    * @param[in] state  The new state of the cell.
    *
    * @return Whether the cell was successfully modified.
    * @retval true  Cell was successfully modified.
    * @retval false Cell was not empty, or out of range.
    */
   bool modifyCell(const unsigned int row,
                   const unsigned int column,
                   const CellState state);

   /**
    * @brief Resets the board to an empty state.
    */
   void reset();

private:
   /**
    * @brief Outputs an ASCII representation of the board.
    */
   friend std::ostream& operator<<(std::ostream& out,
                                   const Board& board);
   /**
    * @brief Container for the board cells arranged [ROW][COLUMN].
    */
   std::array<std::array<CellState, BOARD_SIZE>, BOARD_SIZE> mCells;
};

/**
 * @brief Outputs an ASCII representation of the cell state.
 */
std::ostream& operator<<(std::ostream& out,
                         const CellState state);

/**
 * @copydoc Board::std::ostream& operator<<
 */
std::ostream& operator<<(std::ostream& out,
                         const Board& board);

} // end TicTacToeGame::

#endif /* BOARD_H_ */
