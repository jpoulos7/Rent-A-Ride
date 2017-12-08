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

}

void RentalManager::rentVehicle(Vehicle v, Customer c) {
    cout << "Cust id: " << c.getCustomerID() << endl;
    cout << "Veh Id: " << v.getCustomerID() << endl;
    v.setCustomerID(1000);
}


int main(int argc, char* argv[]) {

    //RentalManager manager(argv[1].c_str());
    RentalManager manager;
    Customer cust("John", "Poulos", 5);
    Car car1("Toyota", "Camry", 2016, "Blue", 4, -1, 0);
    Vehicle *veh1 = &car1;
    veh1->setCustomerID(3);
    cout << veh1->getCustomerID() << endl;
    car1.setCustomerID(4);
    cout << car1.getCustomerID() << endl;
    manager.rentVehicle(car1, cust);
    cout << veh1->getCustomerID() << endl;

}

