#include <iostream>
#include <string>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"
#include "rentalManager.h"
#include "customer.h"
#include <unordered_set>

using namespace std;

RentalManager::RentalManager(){

}

RentalManager::RentalManager(string filename){

}

void RentalManager::importVehicles(string filename) {
    ifstream file(filename);
    string linebuffer;

    while(getline(file, linebuffer, '\r')) {

    }

}

void RentalManager::addCustomer(Customer c) {
    customers.push_back(c);
}

string RentalManager::getAllCustomers() {
    string list = "";
    for (vector<Customer>::iterator it = customers.begin() ; it != customers.end(); ++it) {
        list += it->toString() + "\n";
    }
    return list;
}

void RentalManager::addVehicle(Vehicle v) {
    allVehicles.push_back(v);
}

string RentalManager::getAllVehicles() {
    string list = "";
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        list += it->toString() + "\n";
    }
    return list;
}

string RentalManager::getAvailable() {
    string list = "";
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->getStatus() == -1){
            list += it->toString() + "\n";
        }
    }
    return list;
}

string RentalManager::getRented() {
    string list = "";
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->getStatus() == 0){
            list += it->toString() + "\n";
        }
    }
    return list;
}

string RentalManager::getDetail() {
    string list = "";
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->getStatus() == 1){
            list += it->toString() + "\n";
        }
    }
    return list;
}

string RentalManager::getRepair() {
    string list = "";
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->getStatus() == 2){
            list += it->toString() + "\n";
        }
    }
    return list;
}

void RentalManager::rentVehicle(Vehicle v, Customer c) {
    v.setCustomerID(c.getCustomerID());

}

void RentalManager::returnVehicle(Vehicle v) {
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->toString() == v.toString()){
            v.setCustomerID(-1);
            v.setStatus(1);
        }
    }
}

void RentalManager::returnVehicleProblems(Vehicle v) {
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->toString() == v.toString()){
            v.setCustomerID(-1);
            v.setStatus(2);
        }
    }
}


void RentalManager::repairVehicle(Vehicle v) {
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->toString() == v.toString()){
            v.setStatus(1);
        }
    }
}

void RentalManager::detailVehicle(Vehicle v) {
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->toString() == v.toString()){
            v.setStatus(-1);
        }
    }
}


int main(int argc, char* argv[]) {

    RentalManager manager;
    Customer cust("John", "Poulos", 0);
    Customer cust1("John", "Poulos", 1);
    Customer cust2("John", "Poulos", 2);

    manager.addCustomer(cust);
    manager.addCustomer(cust1);
    manager.addCustomer(cust2);

    cout << manager.getAllCustomers();

    Car car1("Toyota", "Camry", 2016, "Blue", 4, -1, -1, "C");
    Car car2("Toyota", "prius", 2017, "Blue", 4, -1, 0, "C");
    Car car3("Toyota", "4runner", 2018, "Blue", 4, -1, 1, "C");
    Car car4("Toyota", "lol", 2019, "Blue", 4, -1, 2, "C");

    manager.addVehicle(car1);
    manager.addVehicle(car2);
    manager.addVehicle(car3);
    manager.addVehicle(car4);


    manager.addVehicle(car1);
    manager.addVehicle(car2);
    manager.addVehicle(car3);
    manager.addVehicle(car4);

    cout << manager.getAllVehicles() << endl;
    cout << manager.getAvailable() << endl;
    cout << manager.getRented() << endl;
    cout << manager.getDetail() << endl;
    cout << manager.getRepair() << endl;


}
