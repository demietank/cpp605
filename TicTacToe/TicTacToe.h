/*
 * TicTacToe.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Chris
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "Board.h"

namespace TicTacToeGame
{

/**
 * @brief A turn based console game, Tic Tac Toe. This is a single player game with an AI opponent.
 */
class TicTacToe
{
public:
   /**
    * @brief TicTacToe state machine.
    *
    * @details
    *    Runs the game until a winner is decided or a stalemate is reached.
    */
   void runGame();

private:
   /**
    * @brief Checks whether the game is over.
    *
    * @return Whether the game is over.
    * @retval true  The game is over.
    * @retval false The game is not over.
    */
   bool gameOver() const;

   /**
    * @brief Gets a user input from the console and interprets it as row and column.
    *
    * @details
    *    This is a blocking routine that waits for user input. The input is expected in the form of
    *    [row] [column]. Any other input is discarded and row and column are set to an invalid
    *    index (0).
    *
    * @param[out] row    User selected row, or 0 if invalid format input.
    * @param[out] column User selected column, or 0 if invalid format input.
    */
   void getInput(unsigned int& row,
                 unsigned int& column) const;

   /**
    * @brief The user player (X) makes a move.
    *
    * @details
    *    Prompts the user for input then makes a move. Repeat until a valid move is made.
    *
    * @return Whether the user made a valid move.
    * @retval true  The user made a valid move.
    * @retval false The user was unable to make a valid move - the board is full.
    */
   bool makeMoveUser();

   /**
    * @brief The AI player (Y) makes a move.
    *
    * @details
    *    The AI attempts to make a move on the first free cell.
    *
    * @return Whether the AI made a valid move.
    * @retval true  The AI made a valid move.
    * @retval false The AI was unable to make a valid move - the board is full.
    */
   bool makeMoveAI();

   /**
    * @brief Playing board for the game.
    */
   Board mBoard;
};

} // end TicTacToeGame::

#endif /* TICTACTOE_H_ */
