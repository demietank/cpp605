/*
 * ElevatorSim.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: cmmay
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include <cassert>
#include <cstdlib>

#include "ElevatorSim.h"

namespace elevators
{

/// Constants for this simulation
constexpr FloorNumber BOTTOM_FLOOR = 0;
constexpr FloorNumber TOP_FLOOR = 100;
constexpr unsigned int NUM_ELEVATORS = 4;
constexpr unsigned int ELEVATOR_STOPPING_TIME = 2;
constexpr unsigned int ELEVATOR_CAPACITY = 8;

ElevatorSim::ElevatorSim(std::string&& passengerFilePath,
                         const unsigned int elevatorMovingTime) :
      mPassengerFilePath(std::move(passengerFilePath)),
      mBuilding(BOTTOM_FLOOR, TOP_FLOOR, NUM_ELEVATORS, { ELEVATOR_CAPACITY, ELEVATOR_STOPPING_TIME,
            elevatorMovingTime, BOTTOM_FLOOR, TOP_FLOOR }),
      mCurrentTime(0),
      mPassengersStart(0),
      mPassengersComplete(0),
      mPassengerTravelTime(0),
      mPassengerWaitTime(0)
{
}

ElevatorSim::~ElevatorSim()
{
}

bool ElevatorSim::readPassengerCsv()
{
   bool status = true;

   try
   {
      std::ifstream file(mPassengerFilePath);
      std::string line;
      while (std::getline(file, line))
      {
         bool lineStatus = true;
         int startTime = 0;
         FloorNumber startFloor = 0;
         FloorNumber endFloor = 0;

         // get the tokens
         std::stringstream lineStream(line);
         std::string cell;
         try
         {
            if (std::getline(lineStream, cell, ','))
            {
               startTime = std::stoi(cell, nullptr);
            }
            else
            {
               lineStatus = false;
            }

            if (std::getline(lineStream, cell, ','))
            {
               startFloor = std::stoi(cell, nullptr);
            }
            else
            {
               lineStatus = false;
            }

            if (std::getline(lineStream, cell, ','))
            {
               endFloor = std::stoi(cell, nullptr);
            }
            else
            {
               lineStatus = false;
            }
         }
         catch (const std::invalid_argument& e)
         {
            lineStatus = false;
         }

         if (lineStatus)
         {
            // error handling invalid input out of scope
            assert(startTime >= 0);
            Direction dir = (endFloor - startFloor) > 0 ? Direction::UP : Direction::DOWN;
            PassengerStart newPassenger = std::make_pair(Passenger(dir, endFloor), startFloor);
            mPassengerList.emplace(startTime, newPassenger);
         }
      }

      mPassengersStart = mPassengerList.size();
   }
   catch (...)
   {
      std::cerr << "Failed to read csv file: " << mPassengerFilePath << std::endl;
      status = false;
   }

   return status;
}

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
void ElevatorSim::moveInTime()
{
   // add passengers to simulation for every passenger starting at this time
   auto it = mPassengerList.find(mCurrentTime);
   if (it != mPassengerList.end())
   {
      mBuilding.addPassenger(it->second.first, it->second.second);
   }

   // move passengers between floors and elevators
   auto completedPassengers = mBuilding.disembark();
   for (const auto& passenger : completedPassengers)
   {
      ++mPassengersComplete;
      mPassengerWaitTime += passenger.getWaitTime();
      mPassengerTravelTime += passenger.getTravelTime();
   }

   mBuilding.updateElevatorDestinations();
   mBuilding.addPassengersToElevators();

   // move elevators
   mBuilding.moveElevators();

   // time
   ++mCurrentTime;
   mBuilding.incrementPassengerTime();
}

void ElevatorSim::runSimulation()
{
   if (readPassengerCsv())
   {
      do
      {
         moveInTime();
#if 0
         if (mCurrentTime % 100 == 0)
         {
            std::cout << std::endl << "time: " << mCurrentTime << std::endl;
            std::cout << mBuilding;
         }
#endif
         assert(mCurrentTime < 25000); // ensure it doesn't run forever
      } while (mPassengersComplete < mPassengersStart);
   }

   std::cout << "transported " << mPassengersComplete << " passengers in " << mCurrentTime
         << " seconds" << std::endl;
   std::cout << "average wait time: " << (mPassengerWaitTime / mPassengersComplete) << std::endl;
   std::cout << "average travel time: " << (mPassengerTravelTime / mPassengersComplete)
         << std::endl;
}

} /* namespace elevators */

/**
 * @brief Entry point to the expression tree test.
 */
int main()
{
   using namespace elevators;
   constexpr const char * PASSENGER_FILE = "Mod10_Assignment_Elevators.csv";

   constexpr unsigned int ELEVATOR_MOVING_TIME1 = 10;
   ElevatorSim sim1 { PASSENGER_FILE, ELEVATOR_MOVING_TIME1 };
   std::cout << "sim1: elevator moving time = " << ELEVATOR_MOVING_TIME1 << std::endl;
   sim1.runSimulation();

   constexpr unsigned int ELEVATOR_MOVING_TIME2 = 5;
   ElevatorSim sim2 { PASSENGER_FILE, ELEVATOR_MOVING_TIME2 };
   std::cout << std::endl << "sim2: elevator moving time = " << ELEVATOR_MOVING_TIME2 << std::endl;
   sim2.runSimulation();

   return 0;
}
