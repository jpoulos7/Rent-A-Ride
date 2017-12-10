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
    std::vector<Vehicle> available;
    std::vector<Vehicle> rented;
    std::vector<Vehicle> detailShop;
    std::vector<Vehicle> repairShop;
    std::vector<Customer> customers;
    std::vector<Vehicle> found;
    int idCount;

public:

    //Constructors
    RentalManager();
    RentalManager(string vehicles, string customers);
    void importVehicles(string filename);
    void importCustomers(string filename);

    void addCustomer(Customer c);
    vector<Customer> getAllCustomers();

    void addVehicle(Vehicle v);
    vector<Vehicle> getAllVehicles();

    //Returns the string for each column in the display
    vector<Vehicle> getAvailable();
    vector<Vehicle> getRented();
    vector<Vehicle> getDetail();
    vector<Vehicle> getRepair();
    vector<Vehicle> getFound();

    void rentVehicle(Vehicle *v, Customer *c);
    void returnVehicle(Vehicle v);
    void returnVehicleProblems(Vehicle v);

    void repairVehicle(Vehicle v);
    void detailVehicle(Vehicle v);

    void searchName(string token);



};

#endif
