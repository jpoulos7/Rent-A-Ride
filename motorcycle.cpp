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
 * Implementation file for Motorcycle.
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include "motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(){
    
}

Motorcycle::Motorcycle(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) :  Vehicle(make, model, year, color, numWheels, customerID, status, type) { }

Motorcycle::~Motorcycle(){

}
