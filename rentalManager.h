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
    std::vector<Vehicle> allVehicles;
    //std::vector<Vehicle> available;
    //std::vector<Vehicle> rented;
    //std::vector<Vehicle> detailShop;
    //std::vector<Vehicle> repairShop;
    std::vector<Customer> customers;

public:

    //Constructors
    RentalManager();
    RentalManager(string filename);
    void importVehicles(string filename);

    void addCustomer(Customer c);
    string getAllCustomers();

    void addVehicle(Vehicle v);
    string getAllVehicles();

    //Returns the string for each column in the display
    string getAvailable();
    string getRented();
    string getDetail();
    string getRepair();

    void rentVehicle(Vehicle v, Customer c);
    void returnVehicle(Vehicle v);
    void returnVehicleProblems(Vehicle v);

<<<<<<< HEAD
<<<<<<< HEAD
    void repairVehicle(Vehicle v);
    void detailVehicle(Vehicle v);

=======
>>>>>>> 2a1f6883bb555d71405f19a9ac49c0a7444fc1ea
=======
>>>>>>> 2a1f6883bb555d71405f19a9ac49c0a7444fc1ea


};

#endif
