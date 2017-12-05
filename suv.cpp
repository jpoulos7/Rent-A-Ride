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

SUV::SUV(){
    
}

SUV::SUV(string make, string model, string color, int numWheels, int customerID) {
    this->setMake(make);
    this->setModel(model);
    this->setColor(color);
    this->setNumWheels(numWheels);
    this->setCustomerID(customerID);
}

SUV::~SUV(){

}
