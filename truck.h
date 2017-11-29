/**
 *
 * @file truck.h
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the Truck object.
 *
 */


#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Truck : public Vehicle {

public:

    //Default constructor
    Truck();
    //Constructor for new vehicle
    Truck(string make, string model, string color, int numWheels, int customerNum);
    //Destructor
    ~Truck();

};

#endif
