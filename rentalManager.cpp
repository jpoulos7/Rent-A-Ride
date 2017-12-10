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

RentalManager::RentalManager(){
    idCount = 0;
}

RentalManager::RentalManager(string vehicles, string customers){
    importVehicles(vehicles);
    importCustomers(customers);
}

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

void RentalManager::addCustomer(Customer c) {
    if (c.getCustomerID() == -1){
        c.setCustomerID(idCount);
        idCount++;
    }
    customers.push_back(c);
}

vector<Customer> RentalManager::getAllCustomers() {
    return customers;
}

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

vector<Vehicle> RentalManager::getAllVehicles() {
    return allVehicles;
}

vector<Vehicle> RentalManager::getAvailable() {
    return available;
}

vector<Vehicle> RentalManager::getRented() {
    return rented;
}

vector<Vehicle> RentalManager::getDetail() {
    return detailShop;
}

vector<Vehicle> RentalManager::getRepair() {
    return repairShop;
}

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

vector<Vehicle> RentalManager::getFound(){
    return found;
}

//int main(int argc, char* argv[]) {

//RentalManager manager;
//Customer cust("John", "Poulos", 150);
//    Customer cust1("John", "Poulos", 1);
//    Customer cust2("John", "Poulos", 2);
//
//    manager.addCustomer(cust);
//    manager.addCustomer(cust1);
//    manager.addCustomer(cust2);
//
//    cout << manager.getAllCustomers();
//
//    Car car1("Toyota", "Camry", 2016, "Blue", 4, -1, -1, "C");
//Car car2("Toyota", "prius", 2017, "Blue", 4, -1, -1, "C");
//    Car car3("Toyota", "4runner", 2018, "Blue", 4, -1, 1, "C");
//    Car car4("Toyota", "lol", 2019, "Blue", 4, -1, 2, "C");
//
//    manager.addVehicle(car1);
//    manager.addVehicle(car2);
//    manager.addVehicle(car3);
//    manager.addVehicle(car4);
//
//
//    manager.addVehicle(car1);
//    manager.addVehicle(car2);
//    manager.addVehicle(car3);
//    manager.addVehicle(car4);

//manager.importVehicles("dataset/all_out.csv");
//    cout << "AVAILABLE: \n" << manager.getAvailable() << endl;
//    manager.importCustomers("dataset/customers.csv");
//    cout << "CUSTOMERS: \n" << manager.getAllCustomers() << endl;
//manager.addVehicle(car2);
//cout << manager.getAllVehicles() << endl;


//cout << "RENTED\n" << manager.getRented() << endl;

//manager.rentVehicle(&car2,&cust);

//cout << "AVAILABLE: \n" << manager.getAvailable() << endl;
//cout << "RENTED\n" << manager.getRented() << endl;

//car2.setCustomerID(431424);
//car2.setStatus(100000);

//cout << "RENTED\n" << manager.getRented() << endl;
//cout << manager.getAllVehicles() << endl;

//cout << manager.getDetail() << endl;
//cout << manager.getRepair() << endl;
//}
