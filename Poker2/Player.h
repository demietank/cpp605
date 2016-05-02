/*
 * Player.h
 *
 *  Created on: May 1, 2016
 *      Author: cmmay
 */

#ifndef PLAYER_H_
#define PLAYER_H_

namespace pokergame
{

using Chip = unsigned int;

class Player
{
public:
   Player();
   virtual ~Player();

   void addChips(const Chip numChips);

   void removeChips(const Chip numChips);

   Chip getChips() const
   {
      return mChips;
   }

   bool isActive() const
   {
      return mIsActive;
   }

   void setIsActive(const bool isActive);

   bool inHand() const
   {
      return mInHand;
   }

   void setInHand(const bool inHand);

private:
   Chip mChips;
   bool mIsActive;
   bool mInHand;
};

} /* namespace pokergame */

#endif /* PLAYER_H_ */
