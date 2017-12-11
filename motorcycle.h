/**
 *
 * @file motorcycle.h
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the Motorcycle object.
 *
 */

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Motorcycle : public Vehicle {

public:

    //Default constructor
    Motorcycle();
    //Constructor for new vehicle
    Motorcycle(string make, string model, int year, string color, int numWheels, int customerNum, int status, string type);
    //Destructor
    ~Motorcycle();

};

#endif
