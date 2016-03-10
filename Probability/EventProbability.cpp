/*
 * EventProbability.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: j23210
 */

#include <cmath>

#include "EventProbability.h"

namespace probability
{

EventProbability::EventProbability(const double probability) :
      mProbability(probability)
{
   // constrain, if necessary
   if (mProbability > PROBABILITY_MAX)
   {
      mProbability = PROBABILITY_MAX;
   }
   else if (mProbability < PROBABILITY_MIN)
   {
      mProbability = PROBABILITY_MIN;
   }
}

EventProbability operator&(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // AB
   return lhs.getProbability() * rhs.getProbability();
}

EventProbability operator|(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // P(A and B) = P(A) · P(B)
   auto raw = lhs.getProbability() + rhs.getProbability();
   return raw;
   // Ensure bounds
   //return EventProbability(raw).getProbability();
}

EventProbability operator^(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // (A + B) - AB
   auto raw = EventProbability(lhs | rhs).getProbability()
         - EventProbability(lhs & rhs).getProbability();
   return raw;
   // Ensure bounds
   //return EventProbability(raw).getProbability();
}

EventProbability operator-(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // A - AB
   auto raw = lhs.getProbability() - EventProbability(lhs & rhs).getProbability();
   return raw;
   // Ensure bounds
   //return EventProbability(raw).getProbability();
}

EventProbability operator~(const EventProbability& lhs)
{
   return PROBABILITY_MAX - lhs.getProbability();
}

bool operator==(const EventProbability& lhs,
                const EventProbability& rhs)
{
   constexpr const double DELTA = 1.0 / 1000000.0;

   if (fabs(lhs.getProbability() - rhs.getProbability()) < DELTA)
   {
      return true;
   }
   else
   {
      return false;
   }
}

} /* namespace probability */
