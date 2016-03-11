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
   // P(A and B) = P(A) * P(B)
   return lhs.getProbability() * rhs.getProbability();
}

EventProbability operator|(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // P(A or B) = P(A) + P(B) - P(A and B)
   return lhs.getProbability() + rhs.getProbability() - (lhs & rhs).getProbability();
}

EventProbability operator^(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // P(A or B) - P(A and B)
   return (lhs | rhs).getProbability() - (lhs & rhs).getProbability();
}

EventProbability operator-(const EventProbability& lhs,
                 const EventProbability& rhs)
{
   // P(A and not B) = P(A) - P(A and B)
   return lhs.getProbability() - (lhs & rhs).getProbability();
}

EventProbability operator~(const EventProbability& lhs)
{
   // P(not A) = 1 - P(A)
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

