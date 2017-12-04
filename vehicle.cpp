/**
 *
 * @file vehicle.cpp
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for vehicle.
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include "vehicle.h"

using namespace std;



Vehicle::Vehicle(){

}

Vehicle::Vehicle(string make, string model, string color, int numWheels, int customerNum) {
	this.make = make;
	this.model = model;
	this.color = color;
	this.numWheels = numWheels;
	this.customerNum = customerNum;
}

Vehicle::~Vehicle(){

}


string Vehicle::getColor() {
	return color
}

string Vehicle::getMake() {
	return make
}

string Vehicle::getModel() {
	return model
}

int Vehicle::getCustomerNum() {
	return customerNum;
}

int Vehicle::getNumwheels() {
	return numWheels;
}



