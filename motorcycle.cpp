/**
 *
 * @file motorcycle.cpp
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for Motorcycle, child of car.cpp.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "motorcycle.h"

using namespace std;

/**
 * Motorcycle class constructor.
 **/
Motorcycle::Motorcycle(){

}

/**
 * Motorcycle class constructor takes in several parameters that apply to a Motorcycle object.
 **/
Motorcycle::Motorcycle(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) :  Vehicle(make, model, year, color, numWheels, customerID, status, type) { }

/**
 * Destructor
 **/
Motorcycle::~Motorcycle(){
    
}
