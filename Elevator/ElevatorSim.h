/*
 * ElevatorSim.h
 *
 *  Created on: Apr 17, 2016
 *      Author: cmmay
 */

#ifndef ELEVATORSIM_H_
#define ELEVATORSIM_H_

#include <map>
#include <string>

#include "common.h"
#include "Building.h"
#include "Elevator.h"
#include "Passenger.h"

namespace elevators
{

/// A passenger and its starting floor when entering the simulation
using PassengerStart = std::pair<Passenger, FloorNumber>;

/// A simulation of the building, it's elevators and passengers.
/// A number of passengers are trying to travel to different floors.
/// This simulates the time needed for them to travel. It is the almighty,
/// the one responsible for moving the passengers from one area to the next.
class ElevatorSim
{
public:
   ElevatorSim(std::string&& passengerFilePath,
               const unsigned int elevatorMovingTime);
   virtual ~ElevatorSim();

   /// Run the simulation until all passengers have reached their destination.
   /// Output statistics once complete.
   void runSimulation();

private:
   /// Run the simulation for 1 second.
   /// This progresses in the following stages:
   /// If any passengers are starting at the current time, add them to their floors.
   /// Elevator:
   ////   Disembark and update the aggregate times.
   ///    Update elevator destination lists.
   ///    Add passengers to elevators stopped at floors.
   /// Time:
   ///    Increment simulation time.
   ///    For every passenger on a floor, increment their waiting time.
   ///    For every passenger on an elevator, increment their travel time.
   void moveInTime();

   /// Read the associated passenger list csv file and populate mPassengerList
   bool readPassengerCsv();

   /// File path of the CSV file containing the passengers to simulate
   std::string mPassengerFilePath;

   /// The building owned by the simulation
   Building mBuilding;

   /// Current time of the simulation, in seconds.
   unsigned int mCurrentTime;

   /// Number of passengers who will be traveling in the simulation.
   unsigned int mPassengersStart;

   /// Number of passengers who have reached their destination.
   unsigned int mPassengersComplete;

   /// Aggregate of completed passenger travel time.
   unsigned int mPassengerTravelTime;

   /// Aggregate of completed passenger waiting time.
   unsigned int mPassengerWaitTime;

   /// List of passengers that will ride the elevator, keyed by their start time
   /// multiple passengers may have the same start time.
   std::multimap<unsigned int, PassengerStart> mPassengerList;
};

} /* namespace elevators */

#endif /* ELEVATORSIM_H_ */
