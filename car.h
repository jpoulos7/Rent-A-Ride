/**
 *
 * @file car.h
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the car object.
 *
 */


#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Car : public Vehicle {

public:

    //Default constructor
    Car();
    //Constructor for new vehicle
    Car(string make, string model, string color, int numWheels, int customerID);
    //Destructor
    ~Car();
    
};

#endif
