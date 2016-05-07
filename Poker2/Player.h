/*
 * Player.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <ostream>
#include <string>

#include "common.h"
#include "Card.h"
#include "Hand.h"

namespace pokergame
{

class Player
{
public:
   // Constructs a player with no chips and no cards.
   Player(const unsigned int id);
   virtual ~Player();

   // Add cards to the players hand.
   void addCard(const Card card);

   // Add chips to the player's stack.
   void addChips(const Chip numChips);

   // Add chips from the players stack to the pot.
   // Player's pot commitment tracked internally.
   void addChipsToPot(const Chip numChips);

   // Clear the player's pot commitment.
   void clearChipsInPot();

   // Clear the players hand.
   CardCont clearHand();

   // Set whether the player is active in the game.
   void setIsActive(const bool isActive);

   // Set whether the player is in the hand.
   void setInHand(const bool inHand);

   // Makes a Hand used for comparison.
   Hand makeHand() const;

   // Instruct the player to make a move based on a pot minimum.
   PlayerMove makeMove(const Chip potMinimum, Chip& raise);

   // Returns the player's ID.
   unsigned int getId() const
   {
      return mId;
   }

   // Returns the player's chip stack.
   Chip getChips() const
   {
      return mChips;
   }

   // Returns the player's pot commitment.
   Chip getChipsInPot() const
   {
      return mChipsInPot;
   }

   // Returns whether the player is active in the game.
   bool isActive() const
   {
      return mIsActive;
   }

   // Returns whether the player is active in the hand.
   bool inHand() const
   {
      return mInHand;
   }

private:
   /// Outputs an ASCII representation of the card.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Player& player);
   unsigned int mId; // Player ID
   Chip mChips;      // Player chip stack.
   bool mIsActive;   // Whether the player is active in the game.
   bool mInHand;     // Whether the player is active in the hand.
   CardCont mHand;   // Cards in the player's hand.
   Chip mChipsInPot; // Player's pot commitment.
};

/// Outputs an ASCII representation of the card.
std::ostream& operator<<(std::ostream& out,
                         const Player& player);

// Output a prompt to the user and get a valid response.
void getUserInput(const std::string& message, int& userInput);
void getUserInput(const std::string& message, unsigned int& userInput);
void getUserInput(const std::string& message, bool& yes);

} /* namespace pokergame */

#endif /* PLAYER_H_ */
