/**
 *
 * @file truck.cpp
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for truck.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "truck.h"

using namespace std;

/**
 * Truck class constructor.
 **/
Truck::Truck(){

}

/**
 * Truck class constructor takes in several parameters that apply to a Truck object.
 **/
Truck::Truck(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) :  Vehicle(make, model, year, color, numWheels, customerID, status, type) { }


/**
 * Destructor
 **/
Truck::~Truck(){
    
}
