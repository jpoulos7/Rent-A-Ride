/**
 *
 * @file rentalManager.cpp
 * @author John Poulos, jpoulos2
 * @author Mohammad Salad
 * @author Charles Valdez
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation file for rentalManager
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"
#include "rentalManager.h"
#include "customer.h"

using namespace std;

/**
 *Default Constructor
 */
RentalManager::RentalManager(){
    idCount = 0;
}

/**
 *Constructor accepts filename containing vehicles and customers.
 */
RentalManager::RentalManager(string vehicles, string customers){
    importVehicles(vehicles);
    importCustomers(customers);
}

/**
 * Reads vehicles from a file and imports them into the program.
 *
 * @param filename Filename containing vehicles
 * @return none
 */
void RentalManager::importVehicles(string filename) {
    ifstream file(filename);
    string linebuffer, token;
    string veh[8];
    int count = 0;
    while(getline(file, linebuffer, '\n')) {
        istringstream ss(linebuffer);
        count = 0;
        while(getline(ss, token, ',')) {
            veh[count] = token;
            count++;
        }
        if(veh[7] == "C") {
            Car car1(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],atoi(veh[4].c_str()),atoi(veh[5].c_str()),atoi(veh[6].c_str()),veh[7]);
            addVehicle(car1);
        }
        if(veh[7] == "T") {
            Truck truck1(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],atoi(veh[4].c_str()),atoi(veh[5].c_str()),atoi(veh[6].c_str()),veh[7]);
            addVehicle(truck1);
        }
        if(veh[7] == "S") {
            SUV suv1(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],atoi(veh[4].c_str()),atoi(veh[5].c_str()),atoi(veh[6].c_str()),veh[7]);
            addVehicle(suv1);
        }
        if(veh[7] == "M") {
            Motorcycle motorcycle1(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],atoi(veh[4].c_str()),atoi(veh[5].c_str()),atoi(veh[6].c_str()),veh[7]);
            addVehicle(motorcycle1);
        }
    }
}

/**
 * Reads customers from a file and imports them into the program.
 *
 * @param filename Filename containing customers
 * @return none
 */
void RentalManager::importCustomers(string filename) {
    ifstream file(filename);
    string linebuffer, token;
    string cust[2];
    int count = 0;
    idCount = 0;
    while(getline(file, linebuffer, '\n')) {
        istringstream ss(linebuffer);
        count = 0;
        while(getline(ss, token, ',')) {
            cust[count] = token;
            count++;
        }
        Customer cust1(cust[0],cust[1],idCount);
        idCount++;
        addCustomer(cust1);
    }
}

/**
 * Adds a customer to the list of customers.
 *
 * @param Customer Customer to be added to the list
 * @return none
 */
void RentalManager::addCustomer(Customer c) {
    if (c.getCustomerID() == -1){
        c.setCustomerID(idCount);
        idCount++;
    }
    customers.push_back(c);
}

/**
 * Returns a vector list containing all the customers in the list.
 *
 * @param none
 * @return customers vector
 */
vector<Customer> RentalManager::getAllCustomers() {
    return customers;
}

/**
 * Adds a vehicle to the appropriate vector list.
 *
 * @param v Vehicle to be added
 * @return none
 */
void RentalManager::addVehicle(Vehicle v) {
    if (v.getStatus() == -1) {
        available.push_back(v);
    }
    if (v.getStatus() == 0) {
        rented.push_back(v);
    }
    if (v.getStatus() == 1) {
        detailShop.push_back(v);
    }
    if (v.getStatus() == 2) {
        repairShop.push_back(v);
    }
}

/**
 * Returns a vector list containing all the vehicles in the database.
 *
 * @param none
 * @return vector of all vehicles
 */
vector<Vehicle> RentalManager::getAllVehicles() {
    return allVehicles;
}

/**
 * Returns a vector list containing all the available vehicles in the database.
 *
 * @param none
 * @return vector of all available vehicles
 */
vector<Vehicle> RentalManager::getAvailable() {
    return available;
}

/**
 * Returns a vector list containing all the rented vehicles in the database.
 *
 * @param none
 * @return vector of all rented vehicles
 */
vector<Vehicle> RentalManager::getRented() {
    return rented;
}

/**
 * Returns a vector list containing all the vehicles in the detail shop.
 *
 * @param none
 * @return vector of all vehicles in detail shop
 */
vector<Vehicle> RentalManager::getDetail() {
    return detailShop;
}

/**
 * Returns a vector list containing all the vehicles in the repair shop.
 *
 * @param none
 * @return vector of all vehicles in the repair shop
 */
vector<Vehicle> RentalManager::getRepair() {
    return repairShop;
}

/**
 * Takes a vehicle and assigns a customer to that vehicle. Also changes
 * the status of the vehicle to rented and moves it to the list of rented vehicles.
 *
 * @param v Vehicle to be rented
 * @param c Customer renting the vehicle
 * @return none
 */
void RentalManager::rentVehicle(Vehicle *v, Customer *c) {
    for (int i = 0; i < available.size(); i++){
        if (available[i].toString() == v->toString()){
            available[i].setStatus(0);
            available[i].setCustomerID(c->getCustomerID());
            rented.push_back(available[i]);
            available.erase(available.begin() + i);
            return;
        }
    }
}

/**
 * Returns a rented vehicle. Changes the status to needs detailing and removes the customer id.
 * Also puts the vehicle in the detail queue.
 *
 * @param v Vehicle to be returned
 * @return none
 */
void RentalManager::returnVehicle(Vehicle v) {
    for (int i = 0; i < rented.size(); i++){
        if (rented[i].toStringRented() == v.toStringRented()){
            rented[i].setStatus(1);
            rented[i].setCustomerID(-1);
            detailShop.push_back(rented[i]);
            rented.erase(rented.begin() + i);
            return;
        }
    }

}

/**
 * Returns a rented vehicle that has problems. Changes the status to need repair and removes the customer id.
 * Also puts the vehicle in the repair queue.
 *
 * @param v Vehicle to be returned with problems
 * @return none
 */
void RentalManager::returnVehicleProblems(Vehicle v) {
    for (int i = 0; i < rented.size(); i++){
        if (rented[i].toStringRented() == v.toStringRented()){
            rented[i].setStatus(2);
            rented[i].setCustomerID(-1);
            repairShop.push_back(rented[i]);
            rented.erase(rented.begin() + i);
            return;
        }
    }
}

/**
 * Repairs a given vehicle. Moves the vehicle into the detail queue and changes the status to needs detailing.
 *
 * @param v Vehicle that is being repaired
 * @return none
 */
void RentalManager::repairVehicle(Vehicle v) {
    for (int i = 0; i < repairShop.size(); i++){
        if (repairShop[i].toString() == v.toString()){
            repairShop[i].setStatus(1);
            detailShop.push_back(repairShop[i]);
            repairShop.erase(repairShop.begin() + i);
            return;
        }
    }
}

/**
 * Details a given vehicle. Moves the vehicle into the available queue and changes the status to available.
 *
 * @param v Vehicle that is being detailed
 * @return none
 */
void RentalManager::detailVehicle(Vehicle v) {
    for (int i = 0; i < detailShop.size(); i++){
        if (detailShop[i].toString() == v.toString()){
            detailShop[i].setStatus(-1);
            available.push_back(detailShop[i]);
            detailShop.erase(detailShop.begin() + i);
            return;
        }
    }
}

/**
 * Searches the list of rented vehicles looking for all vehicles rented by a particular customer.
 *
 * @param token String that is being searched for (customer firstname, lastname or id)
 * @return none
 */
void RentalManager::searchName(string token) {
    //vector<Customer> found;
    found.clear();
    int id = -1;
    for (int i = 0; i < customers.size(); i++){
        if (customers[i].getFirstName() == token || customers[i].getLastName() == token || customers[i].getCustomerID() == atoi(token.c_str())){
            id = customers[i].getCustomerID();
        }
    }

    for (int i = 0; i < rented.size(); i++){
        if(rented[i].getCustomerID() == id){
            found.push_back(rented[i]);
        }
    }
}

/**
 * Returns the vector containing all the vehicles found during the search query.
 *
 * @param none
 * @return vector containing all vehicles belonging to the specific user
 */
vector<Vehicle> RentalManager::getFound(){
    return found;
}
