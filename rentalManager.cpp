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
        list += it->toString() + " STATUS: " + to_string(it->getStatus()) + "\n";
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
        //cout << "STATUS: " << it->getStatus() << endl;
        if(it->getStatus() == 0){
            //cout << "Found rented! " << it->toString() << endl;
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

void RentalManager::rentVehicle(Vehicle *v, Customer *c) {
    for (vector<Vehicle>::iterator it = allVehicles.begin() ; it != allVehicles.end(); ++it) {
        if(it->toString() == v->toString()){
            it->setStatus(0);
            it->setCustomerID(c->getCustomerID());
        }
    }

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

    manager.importVehicles("dataset/all_out.csv");
    cout << "AVAILABLE: \n" << manager.getAvailable() << endl;
    manager.importCustomers("dataset/customers.csv");
    cout << "CUSTOMERS: \n" << manager.getAllCustomers() << endl;
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
}
