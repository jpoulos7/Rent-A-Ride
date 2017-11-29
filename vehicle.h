/**
 *
 * @file vehicle.h
 * @author John Poulos, jpoulos2
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the vehicle object.
 *
 */


#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vehicle {

private:
    string make;
    string model;
    string color;
    int numWheels;
    int customerNum;

public:

    //Default constructor
    Vehicle();
    //Constructor for new vehicle
    Vehicle(string make, string model, string color, int numWheels, int customerNum);
    //Destructor
    ~Vehicle();

};

#endif
