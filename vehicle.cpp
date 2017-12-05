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

Vehicle::Vehicle(string make, string model, int year, string color, int numWheels, int customerID) {
	this->make = make;
	this->model = model;
    this->year = year;
	this->color = color;
	this->numWheels = numWheels;
	this->customerID = customerID;
}

Vehicle::~Vehicle(){

}

void Vehicle::setMake(string make) {
    this->make = make;
}

string Vehicle::getMake() {
    return make;
}

void Vehicle::setModel(string model) {
    this->model = model;
}

string Vehicle::getModel() {
    return model;
}

void Vehicle::setYear(int year) {
    this->year = year;
}

int Vehicle::getYear() {
    return year;
}

void Vehicle::setColor(string color) {
    this->color = color;
}

string Vehicle::getColor() {
    return color;
}

void Vehicle::setNumWheels(int numWheels) {
    this->numWheels = numWheels;
}

int Vehicle::getNumWheels() {
    return numWheels;
}

void Vehicle::setCustomerID(int customerID) {
    this->customerID = customerID;
}

int Vehicle::getCustomerID() {
	return customerID;
}




