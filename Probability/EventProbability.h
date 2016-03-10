/*
 * EventProbability.h
 *
 *  Created on: Mar 9, 2016
 *      Author: j23210
 */

#ifndef EVENTPROBABILITY_H_
#define EVENTPROBABILITY_H_

namespace probability
{

/// Maximum likelihood of an event.
constexpr const double PROBABILITY_MIN = 0.0;

/// Minimum likelihood of an event.
constexpr const double PROBABILITY_MAX = 1.0;

/// Class that encapsulates the probability of an independent event based on an expected likelihood.
class EventProbability
{
public:
   /// Constructs an EventProbabilty based on an expected likelihood.
   /// The likelihood is constrained to PROBABILITY_MIN and PROBABILITY_MAX.
   EventProbability(const double probability);

   /// Returns the likelihood of this event.
   double getProbability() const
   {
      return mProbability;
   }

private:
   double mProbability;
};

/// Returns the likelihood of both A (lhs) and B (rhs) occurring.
EventProbability operator&(const EventProbability& lhs,
                 const EventProbability& rhs);

/// Returns the likelihood of either A (lhs) or B (rhs) occurring.
EventProbability operator|(const EventProbability& lhs,
                 const EventProbability& rhs);

/// Returns the likelihood of either A (lhs) or B (rhs), but not both, occurring.
EventProbability operator^(const EventProbability& lhs,
                 const EventProbability& rhs);

/// Returns the likelihood of A (lhs), but not  B (rhs), occurring.
EventProbability operator-(const EventProbability& lhs,
                 const EventProbability& rhs);

/// Returns the likelihood of A (lhs) not occurring.
EventProbability operator~(const EventProbability& lhs);


/// Determines the equality of two EventProbability, accounting for minute deltas.
/// True if the doubles can be considered equal.
bool operator==(const EventProbability& lhs, const EventProbability& rhs);
inline bool operator!=(const EventProbability& lhs, const EventProbability& rhs) { return !(lhs == rhs); }

} /* namespace probability */

#endif /* EVENTPROBABILITY_H_ */
