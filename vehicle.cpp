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
 * Implementation file for vehicle, parent to all vehicle objects.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vehicle.h"

using namespace std;

/**
 * Vehicle class constructor.
 **/
Vehicle::Vehicle(){

}

/**
 * Vehicle class constructor takes in several parameters that apply to a Vehicle object.
 * @param make				manufacturer of vehicle
 * @param model			variation of vehicle
 * @param year				when vehicle started to be in production
 * @param color			color of vehicle
 * @param numWheels	number of wheels
 * @param customerID	identification of customer object
 * @param status			current state of vehicle object
 * @param type				the type of vehicle M, C, or T
 **/
Vehicle::Vehicle(string make, string model, int year, string color, int numWheels, int customerID, int status, string type) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
    this->numWheels = numWheels;
    this->customerID = customerID;
    this->status = status;
    this->type = type;
}

/**
 * Destructor
 **/
Vehicle::~Vehicle(){

}

/**
 * Function populates make with string.
 * @param make
 * @return none
 **/
void Vehicle::setMake(string make) {
    this->make = make;
}

/**
 * Fucntion returns the make of Vehicle.
 * @return make
 **/
string Vehicle::getMake() {
    return make;
}

/**
 * Function populates model with string.
 * @param model
 * @return none
 **/
void Vehicle::setModel(string model) {
    this->model = model;
}

/**
 * Fucntion returns the model of Vehicle.
 * @return model
 **/
string Vehicle::getModel() {
    return model;
}

/**
 * Function populates year with string.
 * @param year
 * @return none
 **/
void Vehicle::setYear(int year) {
    this->year = year;
}

/**
 * Fucntion returns the year of Vehicle.
 * @return year
 **/
int Vehicle::getYear() {
    return year;
}

/**
 * Function populates color with string.
 * @param color
 * @return none
 **/
void Vehicle::setColor(string color) {
    this->color = color;
}

/**
 * Fucntion returns the color of Vehicle.
 * @return color
 **/
string Vehicle::getColor() {
    return color;
}

/**
 * Function populates numWheels with string.
 * @param numWheels
 * @return none
 **/
void Vehicle::setNumWheels(int numWheels) {
    this->numWheels = numWheels;
}

/**
 * Fucntion returns the number of wheels of a Vehicle.
 * @return numWheels
 **/
int Vehicle::getNumWheels() {
    return numWheels;
}

/**
 * Function populates customerID with string.
 * @param customerID
 * @return none
 **/
void Vehicle::setCustomerID(int customerID) {
    this->customerID = customerID;
}

/**
 * Fucntion returns the customerID of Customer.
 * @return customerID
 **/
int Vehicle::getCustomerID() {
    return customerID;
}

/**
 * Function populates status with string.
 * @param status
 * @return none
 **/
void Vehicle::setStatus(int status) {
    this->status = status;
}

/**
 * Fucntion returns the status of Vehicle.
 * @return status
 **/
int Vehicle::getStatus() {
    return status;
}

/**
 * Function populates type with string.
 * @param type
 * @return none
 **/
void Vehicle::setType(string type) {
    this->type = type;
}

/**
 * Fucntion returns the type of Vehicle.
 * @return type
 **/
string Vehicle::getType() {
    return type;
}

/**
 * Fucntion returns a string formated to "make model year color type"
 **/
string Vehicle::toString(){
    return make + " " + model + " " + to_string(year) + " " + color + " " + type;
}

/**
 * Fucntion returns a string formated to "make model year color type"
 **/
string Vehicle::toStringRented(){
    return make + " " + model + " " + to_string(year) + " " + color + " " + type + " " + to_string(customerID);
}
