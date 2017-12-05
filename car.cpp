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

Car::Car(){

}

Car::Car(string make, string model, string color, int numWheels, int customerID) {
    this->setMake(make);
    this->setModel(model);
    this->setColor(color);
    this->setNumWheels(numWheels);
    this->setCustomerID(customerID);
}

Car::~Car(){
    
}
