/**
 *
 * @file suv.h
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the SUV object.
 *
 */


#ifndef SUV_H
#define SUV_H

#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SUV : public Vehicle {

public:

    //Default constructor
    SUV();
    //Constructor for new vehicle
    SUV(string make, string model, int year, string color, int numWheels, int customerNum);
    //Destructor
    ~SUV();

};

#endif
