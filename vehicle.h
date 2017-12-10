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

protected:
    string make;
    string model;
    int year;
    string color;
    int numWheels;
    int customerID;
    int status;
    string type;

public:

    //Default constructor
    Vehicle();
    //Constructor for new vehicle
    Vehicle(string make, string model, int year, string color, int numWheels, int customerID, int status, string type);
    //Destructor
    ~Vehicle();
    void setMake(string make);
    string getMake();
    void setModel(string model);
    string getModel();
    void setYear(int year);
    int getYear();
    void setColor(string color);
    string getColor();
    void setNumWheels(int numWheels);
	int getNumWheels();
    void setCustomerID(int customerID);
	int getCustomerID();
    void setStatus(int status);
    int getStatus();
    void setType(string type);
    string getType();
    string toString();
    string toStringRented();

};

#endif
