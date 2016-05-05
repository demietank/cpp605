/*
 * Player.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <ostream>

#include "common.h"
#include "Card.h"

namespace pokergame
{

class Player
{
public:
   Player(const unsigned int id);
   virtual ~Player();

   void addCard(const Card card);
   void addChips(const Chip numChips);
   void addChipsToPot(const Chip numChips);
   void clearChipsInPot();
   void setIsActive(const bool isActive);
   void setInHand(const bool inHand);

   unsigned int getId() const
   {
      return mId;
   }

   Chip getChips() const
   {
      return mChips;
   }

   Chip getChipsInPot() const
   {
      return mChipsInPot;
   }

   bool isActive() const
   {
      return mIsActive;
   }

   bool inHand() const
   {
      return mInHand;
   }

private:
   /// Outputs an ASCII representation of the card.
   friend std::ostream& operator<<(std::ostream& out,
                                   const Player& player);

   unsigned int mId;
   Chip mChips;
   bool mIsActive;
   bool mInHand;
   CardCont mHand;
   Chip mChipsInPot;
};

/// Outputs an ASCII representation of the card.
std::ostream& operator<<(std::ostream& out,
                         const Player& player);

} /* namespace pokergame */

#endif /* PLAYER_H_ */
