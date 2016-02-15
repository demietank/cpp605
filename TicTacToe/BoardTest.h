/*
 * BoardTest.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Chris
 */

#ifndef BOARDTEST_H_
#define BOARDTEST_H_

namespace TicTacToeGame
{

/**
 * @brief Class that tests the Board class.
 */
class BoardTest
{
public:
   /**
    * @brief Performs unit testing on the Board class.
    *
    * @retval Whether the test was successful.
    */
   static bool testBoard();

private:
   /**
    * @brief Perform negative testing on Board::modifyCell()
    */
   static bool testModifyCell();

   /**
    * @brief Perform testing on Board::hasWinner() row logic.
    */
   static bool testRowWinner();

   /**
    * @brief Perform testing on Board::hasWinner() column logic.
    */
   static bool testColWinner();

   /**
    * @brief Perform testing on Board::hasWinner() column logic.
    */
   static bool testDiagWinner();

   /**
    * @brief Performs testing on Board::isFull().
    */
   static bool testIsFull();
};

} // end TicTacToeGame::

#endif /* BOARDTEST_H_ */
