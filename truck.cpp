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

Truck::Truck(){
    
}

Truck::Truck(string make, string model, int year, string color, int numWheels, int customerID) {
    this->setMake(make);
    this->setModel(model);
    this->setYear(year);
    this->setColor(color);
    this->setNumWheels(numWheels);
    this->setCustomerID(customerID);
}

Truck::~Truck(){

}
