/**
 *
 * @file rentalManager.h
 * @author John Poulos, jpoulos2
 * @date Dec 2, 2017
 *
 * @brief ITCS 3112 Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for rentalManager
 *
 */

#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"
#include "customer.h"


class RentalManager {
private:

    //std::unordered_set<Car> available;
    std::vector<Vehicle> available;

public:

    //Constructors
    RentalManager();
    RentalManager(string filename);
    void importVehicles(string filename);
    void rentVehicle(Vehicle v, Customer c);
    
};

#endif
