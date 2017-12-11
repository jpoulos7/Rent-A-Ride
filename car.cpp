/**
 *
 * @file car.cpp
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for car.
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include "car.h"

using namespace std;

/**
 * Car class constructor.
 **/
Car::Car(){

}

/**
 * Car class constructor takes in several parameters that apply to a Car object.
 **/
Car::Car(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) :  Vehicle(make, model, year, color, numWheels, customerID, status, type) { }

/**
 * Destructor
 **/
Car::~Car(){
    
}
