/*
 * common.h
 *
 *  Created on: May 4, 2016
 *      Author: cmmay
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <vector>

#include "Card.h"

namespace pokergame
{

/// Used for convenience
using Chip = unsigned int;
using CardCont = std::vector<Card>;

// Moves a player can take when given the action.
enum class PlayerMove
{
   FOLD,    // Fold the hand
   STAND,   // Take no action
   CALL,    // Call the raise
   RAISE    // Raise amount
};

constexpr unsigned int CARDS_PER_HAND = 5;

} /* namespace pokergame */

#endif /* COMMON_H_ */
