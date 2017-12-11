/**
 *
 * @file suv.cpp
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for SUV.
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include "suv.h"

using namespace std;

/**
* SUV class constructor.
**/
SUV::SUV(){

}

/**
* SUV class constructor takes in several parameters that apply to a SUV object.
**/
SUV::SUV(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) :  Vehicle(make, model, year, color, numWheels, customerID, status, type) { }
SUV::~SUV(){

}
